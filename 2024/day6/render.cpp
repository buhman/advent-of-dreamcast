#include "holly/isp_tsp.hpp"
#include "holly/ta_parameter.hpp"
#include "holly/ta_global_parameter.hpp"
#include "holly/ta_vertex_parameter.hpp"

#include "sh7091/store_queue.hpp"
#include "sh7091/serial.hpp"

#include "math/vec2.hpp"
#include "font/font.h"
#include "maple/maple_bus_ft0.hpp"

#include "solution.h"

extern void glyph_start(const uint32_t texture_width, uint32_t texture_height);
extern int32_t transform_char(const uint32_t texture_width,
                              const uint32_t texture_height,
                              const uint32_t first_char_code,
                              const glyph * glyphs,
                              const char c,
                              int32_t horizontal_advance,
                              int32_t vertical_advance);

using vec2 = vec<2, float>;

constexpr vec2 arrow_vertices[] = {
  {-0.1, -0.15},
  { 0.0, -0.45},
  { 0.1, -0.15},
};

constexpr vec2 square_vertices[] = {
  {0.475, 0.525},
  {0.525, 0.525},
  {0.475, 0.475},
  {0.525, 0.475},
};

vec2 rotate(vec2 v, int n) {
  switch (n) {
  case 0: return {v.x, v.y};
  case 1: return {-v.y, v.x};
  case 2: return {-v.x, -v.y};
  case 3: return {v.y, -v.x};
  }
  __builtin_unreachable();
}

void polygon_start()
{
  const uint32_t parameter_control_word = para_control::para_type::polygon_or_modifier_volume
                                        | para_control::list_type::translucent
                                        | obj_control::col_type::packed_color;

  const uint32_t isp_tsp_instruction_word = isp_tsp_instruction_word::depth_compare_mode::always
                                          | isp_tsp_instruction_word::culling_mode::no_culling;

  const uint32_t tsp_instruction_word = tsp_instruction_word::src_alpha_instr::one
                                      | tsp_instruction_word::dst_alpha_instr::zero
                                      | tsp_instruction_word::fog_control::no_fog;

  *reinterpret_cast<ta_global_parameter::polygon_type_0 *>(store_queue) =
    ta_global_parameter::polygon_type_0(parameter_control_word,
                                        isp_tsp_instruction_word,
                                        tsp_instruction_word,
                                        0, // texture_control_word
                                        0, // data_size_for_sort_dma
                                        0  // next_address_for_sort_dma
                                        );
  sq_transfer_32byte(ta_fifo_polygon_converter);
}

constexpr int scale = 45;

void arrow(int cx, int cy, int rotation, uint32_t base_color)
{
  float z = 1.0 / 10.0;

  for (int i = 0; i < 3; i++) {
    bool end_of_strip = i == 2;
    vec2 v = arrow_vertices[i];

    v = rotate(v, rotation);

    v.x *= scale;
    v.y *= scale;
    v.x += scale / 2.0 + (640 - (scale * 10)) / 2 + cx * scale;
    v.y += scale / 2.0 + (480 - (scale * 10)) / 2 + cy * scale;

    *reinterpret_cast<ta_vertex_parameter::polygon_type_0 *>(store_queue) =
      ta_vertex_parameter::polygon_type_0(polygon_vertex_parameter_control_word(end_of_strip),
                                          v.x, v.y, z,
                                          base_color);
    sq_transfer_32byte(ta_fifo_polygon_converter);
  }
}

void border(int cx, int cy, int rotation)
{
  uint32_t base_color = 0xff'ff00ff;
  float z = 1.0 / 10.0;

  for (int i = 0; i < 4; i++) {
    bool end_of_strip = i == 3;
    vec2 v = square_vertices[i];

    v = rotate(v, rotation);

    v.x *= scale;
    v.y *= scale;
    v.x += scale / 2.0 + (640 - (scale * 10)) / 2 + cx * scale;
    v.y += scale / 2.0 + (480 - (scale * 10)) / 2 + cy * scale;

    *reinterpret_cast<ta_vertex_parameter::polygon_type_0 *>(store_queue) =
      ta_vertex_parameter::polygon_type_0(polygon_vertex_parameter_control_word(end_of_strip),
                                          v.x, v.y, z,
                                          base_color);
    sq_transfer_32byte(ta_fifo_polygon_converter);
  }
}

void glyph(const struct font * font,
           const struct glyph * glyphs,
           int cx, int cy,
           char c)
{
  int32_t horizontal_advance = font->face_metrics.max_advance * 2 / 5; // 26.6 fixed point
  int32_t vertical_advance = font->face_metrics.height * 5 / 4; // 26.6 fixed point

  int x = (640 - (scale * 10)) / 2 + cx * scale;
  int y = (480 - (scale * 10)) / 2 + cy * scale;

  horizontal_advance += (x << 6);
  vertical_advance += (y << 6);

  transform_char(font->texture_width,
                 font->texture_height,
                 font->first_char_code,
                 glyphs,
                 c,
                 horizontal_advance,
                 vertical_advance);
}

extern "C" struct solution_state day6_state;

void a_press()
{
  serial::string("press\n");
  serial::integer<uint8_t>(day6_state.part);
  day6_state.step = true;
}

extern "C"
void _2024_day6_render(const struct font * font,
                       const struct glyph * glyphs,
                       ft0::data_transfer::data_format * maple_ft0_data)
{
  return;

  static bool last_a = true;

  if (maple_ft0_data[0].digital_button != 0) {
    bool a = ft0::data_transfer::digital_button::a(maple_ft0_data[0].digital_button) == 0;
    if (a && !last_a) {
      a_press();
    }
    last_a = a;
  }

  polygon_start();

  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      border(x, y, 0);
      border(x, y, 2);
    }
  }
  border(9, 0, 3);
  border(0, 9, 1);

  uint32_t base_color[2] = {
    0xff'00ffff,
    0xff'ff0000,
  };


  for (int y = 0; y < day6_state.height; y++) {
    for (int x = 0; x < day6_state.width; x++) {
      int ix = y * day6_state.width + x;
      unsigned char c = day6_state.visited[ix];

      for (int i = 0; i < 4; i++) {
        if (c & (1 << i)) {
          arrow(x,
                y,
                i,
                0xff'005555);
        }
      }
    }
  }

  arrow(day6_state.guard[0]->position.x,
        day6_state.guard[0]->position.y,
        day6_state.guard[0]->facing,
        base_color[0]);

  // render text
  glyph_start(font->texture_width, font->texture_height);

  glyph(font, glyphs, 11, 0, '0' + day6_state.part);

  for (int y = 0; y < day6_state.height; y++) {
    for (int x = 0; x < day6_state.width; x++) {
      int ix = y * day6_state.stride + x;
      char c = day6_state.input[ix];

      if (c == '#')
        glyph(font, glyphs, x, y, '#');
    }
  }
}
