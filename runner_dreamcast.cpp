#include <cstdint>

#include "holly/texture_memory_alloc2.hpp"
#include "holly/isp_tsp.hpp"
#include "holly/ta_fifo_polygon_converter.hpp"
#include "holly/ta_parameter.hpp"
#include "holly/ta_global_parameter.hpp"
#include "holly/ta_vertex_parameter.hpp"
#include "holly/ta_bits.hpp"
#include "holly/background.hpp"
#include "holly/region_array.hpp"
#include "holly/holly.hpp"
#include "holly/core.hpp"
#include "holly/core_bits.hpp"
#include "holly/video_output.hpp"

#include "sh7091/store_queue.hpp"
#include "sh7091/serial.hpp"

#include "font/font.hpp"
#include "font/dejavusansmono/dejavusansmono.data.h"

#include "palette.hpp"

#include "printf.h"
#include "runner.h"

struct vertex {
  float x;
  float y;
  float z;
  float u;
  float v;
};

const struct vertex strip_vertices[4] = {
  // [ position       ]  [ uv coordinates ]
  { 0.f,  1.f,  0.f, 0.f, 1.f, },
  { 0.f,  0.f,  0.f, 0.f, 0.f, },
  { 1.f,  1.f,  0.f, 1.f, 1.f, },
  { 1.f,  0.f,  0.f, 1.f, 0.f, },
};
constexpr uint32_t strip_length = (sizeof (strip_vertices)) / (sizeof (struct vertex));


void transform_start(const uint32_t texture_width, uint32_t texture_height)
{
  const uint32_t parameter_control_word = para_control::para_type::polygon_or_modifier_volume
                                        | para_control::list_type::translucent
                                        | obj_control::col_type::packed_color
                                        | obj_control::texture;

  const uint32_t isp_tsp_instruction_word = isp_tsp_instruction_word::depth_compare_mode::greater
                                          | isp_tsp_instruction_word::culling_mode::no_culling;

  const uint32_t tsp_instruction_word = tsp_instruction_word::src_alpha_instr::src_alpha
                                      | tsp_instruction_word::dst_alpha_instr::one
                                      | tsp_instruction_word::fog_control::no_fog
                                      | tsp_instruction_word::use_alpha
                                      | tsp_instruction_word::texture_u_size::from_int(texture_width)
                                      | tsp_instruction_word::texture_v_size::from_int(texture_height);

  const uint32_t texture_address = texture_memory_alloc::texture.start;
  const uint32_t texture_control_word = texture_control_word::pixel_format::_8bpp_palette
                                      | texture_control_word::scan_order::twiddled
                                      | texture_control_word::texture_address(texture_address / 8);

  *reinterpret_cast<ta_global_parameter::polygon_type_0 *>(store_queue) =
    ta_global_parameter::polygon_type_0(parameter_control_word,
                                        isp_tsp_instruction_word,
                                        tsp_instruction_word,
                                        texture_control_word,
                                        0, // data_size_for_sort_dma
                                        0  // next_address_for_sort_dma
                                        );
  sq_transfer_32byte(ta_fifo_polygon_converter);
}

int32_t transform_char(const uint32_t texture_width,
                       const uint32_t texture_height,
                       const uint32_t first_char_code,
                       const glyph * glyphs,
                       const char c,
                       int32_t horizontal_advance,
                       int32_t vertical_advance)
{
  auto& glyph = glyphs[c - first_char_code];

  for (uint32_t i = 0; i < strip_length; i++) {
    float x = strip_vertices[i].x;
    float y = strip_vertices[i].y;
    float z = strip_vertices[i].z;

    x *= glyph.bitmap.width;
    y *= glyph.bitmap.height;
    x += (float)(horizontal_advance + glyph.metrics.horiBearingX) / 64.0;
    y += (float)(vertical_advance - glyph.metrics.horiBearingY) / 64.0;
    z = 1.f / (z + 10.f);

    float u = strip_vertices[i].u;
    float v = strip_vertices[i].v;
    u *= glyph.bitmap.width;
    v *= glyph.bitmap.height;
    u += glyph.bitmap.x;
    v += glyph.bitmap.y;
    u = u / static_cast<float>(texture_width);
    v = v / static_cast<float>(texture_height);

    bool end_of_strip = i == strip_length - 1;
    *reinterpret_cast<ta_vertex_parameter::polygon_type_3 *>(store_queue) =
      ta_vertex_parameter::polygon_type_3(polygon_vertex_parameter_control_word(end_of_strip),
                                          x, y, z,
                                          u, v,
                                          0, // base_color
                                          0  // offset_color
                                          );
    sq_transfer_32byte(ta_fifo_polygon_converter);
  }

  return glyph.metrics.horiAdvance;
}

void transfer_scene(const struct font * font,
                    const struct glyph * glyphs)
{
  transform_start(font->texture_width, font->texture_height);

  int32_t horizontal_advance = font->face_metrics.max_advance / 5; // 26.6 fixed point
  int32_t vertical_advance = font->face_metrics.height; // 26.6 fixed point

  for (int i = 0; i < global_output_buffer.buf_ix; i++) {
    char c = global_output_buffer.buf[i];
    if (c < 0x20 && c > 0x7f) {
      continue;
    } else if (c == '\n') {
      horizontal_advance = font->face_metrics.max_advance / 5;
      vertical_advance += font->face_metrics.height;
    } else {
      horizontal_advance += transform_char(font->texture_width,
                                           font->texture_height,
                                           font->first_char_code,
                                           glyphs,
                                           c,
                                           horizontal_advance,
                                           vertical_advance);
    }
  }

  *reinterpret_cast<ta_global_parameter::end_of_list *>(store_queue) =
    ta_global_parameter::end_of_list(para_control::para_type::end_of_list);
  sq_transfer_32byte(ta_fifo_polygon_converter);
}

void copy_font(const uint8_t * src,
               const uint32_t z_curve_max_ix)
{
  auto texture = reinterpret_cast<volatile uint32_t *>(&texture_memory64[texture_memory_alloc::texture.start / 4]);

  for (uint32_t i = 0; i < z_curve_max_ix / 4; i++) {
    texture[i] = reinterpret_cast<const uint32_t *>(src)[i];
  }
}

int main()
{
  serial::init(0);
  serial::string("framebuffer: ");
  serial::integer<uint32_t>((uint32_t)&texture_memory32[texture_memory_alloc::framebuffer[0].start / 4]);

  constexpr uint32_t ta_alloc = ta_alloc_ctrl::pt_opb::no_list
			      | ta_alloc_ctrl::tm_opb::no_list
			      | ta_alloc_ctrl::t_opb::_32x4byte
			      | ta_alloc_ctrl::om_opb::no_list
                              | ta_alloc_ctrl::o_opb::no_list;

  constexpr int render_passes = 1;
  constexpr struct opb_size opb_size[render_passes] = {
    {
      .opaque = 0,
      .opaque_modifier = 0,
      .translucent = 32 * 4,
      .translucent_modifier = 0,
      .punch_through = 0
    }
  };

  holly.SOFTRESET = softreset::pipeline_soft_reset
		  | softreset::ta_soft_reset;
  holly.SOFTRESET = 0;

  core_init();

  constexpr int framebuffer_width = 640;
  constexpr int framebuffer_height = 480;
  constexpr int tile_width = framebuffer_width / 32;
  constexpr int tile_height = framebuffer_height / 32;

  region_array_multipass(tile_width,
			 tile_height,
			 opb_size,
			 render_passes,
			 texture_memory_alloc::region_array[0].start,
			 texture_memory_alloc::object_list[0].start);
  region_array_multipass(tile_width,
			 tile_height,
			 opb_size,
			 render_passes,
			 texture_memory_alloc::region_array[1].start,
			 texture_memory_alloc::object_list[1].start);

  background_parameter2(texture_memory_alloc::background[0].start,
			0xff220033);
  background_parameter2(texture_memory_alloc::background[1].start,
			0xff220033);

  auto font = reinterpret_cast<const struct font *>(&_binary_font_dejavusansmono_dejavusansmono_data_start);
  auto glyphs = reinterpret_cast<const struct glyph *>(&font[1]);
  auto texture = reinterpret_cast<const uint8_t *>(&glyphs[font->glyph_count]);

  copy_font(texture, font->max_z_curve_ix);
  palette_data<256>();

  int ta = -1;
  int core = -2;

  struct runner_state runner_state = {0};

  video_output::set_mode_vga();

  bool done = false;

  while (true) {
    if (core >= 0) {
      // core = 0  ; core = 1
      // ta = 1    ; ta = 0
      core_wait_end_of_render_video();
      while (!spg_status::vsync(holly.SPG_STATUS));
      holly.FB_R_SOF1 = texture_memory_alloc::framebuffer[core].start;
      while (spg_status::vsync(holly.SPG_STATUS));
    }

    if (core == 0) {
      if (done == true)
        break;
      done = runner_tick(&runner_state);
    }

    // core = -2 ; core = 1 ; core = 0
    // ta = -1   ; ta = 0   ; ta = 1
    core += 1;
    ta += 1;
    if (core > 1) core = 0;
    if (ta > 1) ta = 0;

    if (core >= 0) {
      // core = 1 ; core = 0
      // ta = 0   ; ta = 1
      ta_wait_translucent_list();

      core_start_render2(texture_memory_alloc::region_array[core].start,
			 texture_memory_alloc::isp_tsp_parameters[core].start,
			 texture_memory_alloc::background[core].start,
			 texture_memory_alloc::framebuffer[core].start,
			 framebuffer_width);
    }


    // core = -1 ; core = 1 ; core = 0
    // ta = 0    ; ta = 0   ; ta = 1
    ta_polygon_converter_init2(texture_memory_alloc::isp_tsp_parameters[ta].start,
			       texture_memory_alloc::isp_tsp_parameters[ta].end,
			       texture_memory_alloc::object_list[ta].start,
			       texture_memory_alloc::object_list[ta].end,
			       opb_size[0].total(),
			       ta_alloc,
			       tile_width,
			       tile_height);
    transfer_scene(font, glyphs);
  }

  while (1);
  serial::string("return\n");
}
