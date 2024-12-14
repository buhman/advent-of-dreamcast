#include "holly/isp_tsp.hpp"
#include "holly/ta_parameter.hpp"
#include "holly/ta_global_parameter.hpp"
#include "holly/ta_vertex_parameter.hpp"

#include "sh7091/store_queue.hpp"
#include "sh7091/serial.hpp"

#include "math/vec2.hpp"
#include "font/font.h"
#include "maple/maple_bus_ft0.hpp"

#include "unparse.h"
#include "solution.h"

extern void glyph_start(const uint32_t texture_width, uint32_t texture_height);
extern int32_t transform_char(const uint32_t texture_width,
                              const uint32_t texture_height,
                              const uint32_t first_char_code,
                              const glyph * glyphs,
                              const char c,
                              int32_t horizontal_advance,
                              int32_t vertical_advance,
                              uint32_t base_color = 0xffffffff);

using vec2 = vec<2, float>;

constexpr vec2 square_vertices[] = {
  {0.0, 4.0},
  {0.0, 0.0},
  {4.0, 4.0},
  {4.0, 0.0},
};

static void polygon_start()
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

static void draw_robot(int cx, int cy, uint32_t base_color)
{
  float z = 1.0 / 10.0;

  for (int i = 0; i < 4; i++) {
    bool end_of_strip = i == 3;
    vec2 v = square_vertices[i];

    v.x += 118 + 4 * cx;
    v.y += 34 + 4 * cy;

    *reinterpret_cast<ta_vertex_parameter::polygon_type_0 *>(store_queue) =
      ta_vertex_parameter::polygon_type_0(polygon_vertex_parameter_control_word(end_of_strip),
                                          v.x, v.y, z,
                                          base_color);
    sq_transfer_32byte(ta_fifo_polygon_converter);
  }
}

static void draw_time(const struct font * font,
                      const struct glyph * glyphs)
{
  int32_t horizontal_advance = 250 << 6;
  int32_t vertical_advance = font->face_metrics.height;

  {
    char time[64] = "time: ";
    int ix = 6;
    ix += unparse_base10(&time[ix], _2024_day14_state.time, 0, 0);

    for (int i = 0; i < ix; i++) {
      char c = time[i];
      horizontal_advance += transform_char(font->texture_width,
                                           font->texture_height,
                                           font->first_char_code,
                                           glyphs,
                                           c,
                                           horizontal_advance,
                                           vertical_advance);
    }
  }

  {
    horizontal_advance = (450 << 6);
    char max_size[64] = "max_size: ";
    int ix = 10;
    ix += unparse_base10(&max_size[ix], _2024_day14_state.max_size, 0, 0);

    for (int i = 0; i < ix; i++) {
      char c = max_size[i];
      horizontal_advance += transform_char(font->texture_width,
                                           font->texture_height,
                                           font->first_char_code,
                                           glyphs,
                                           c,
                                           horizontal_advance,
                                           vertical_advance);
    }
  }
}

static void draw_christmas(const struct font * font,
                           const struct glyph * glyphs,
                           uint32_t base_color,
                           int x)
{
  int32_t horizontal_advance = (x << 6) + font->face_metrics.max_advance / 2;
  int32_t vertical_advance = (480 << 6) - (font->face_metrics.height / 2);

  char max_size[64] = "christmas detected";

  for (int i = 0; i < 18; i++) {
    char c = max_size[i];
    horizontal_advance += transform_char(font->texture_width,
                                         font->texture_height,
                                         font->first_char_code,
                                         glyphs,
                                         c,
                                         horizontal_advance,
                                         vertical_advance,
                                         base_color);
  }
}

extern "C"
void _2024_day14_render(const struct font * font,
                        const struct glyph * glyphs,
                        ft0::data_transfer::data_format * maple_ft0_data)
{
  static int frame = 0;

  frame += 1;

  static bool last_a = true;
  static bool last_b = true;

  if (maple_ft0_data[0].digital_button != 0) {
    bool a = ft0::data_transfer::digital_button::a(maple_ft0_data[0].digital_button) == 0;
    bool b = ft0::data_transfer::digital_button::b(maple_ft0_data[0].digital_button) == 0;
    if (a && !last_a) {
      _2024_day14_state.step = 1;
    }
    if (b && !last_b) {
      _2024_day14_state.step = -1;
    }
    last_a = a;
    last_b = b;
  }

  polygon_start();

  uint32_t red_and_green[2] = {
    0xffff0000,
    0xff00ff00,
  };

  uint32_t base_color = 0xff00ffff;
  uint32_t font_color = 0xffffffff;
  if (_2024_day14_state.step == 0 && _2024_day14_state.max_size > 200) {
    int robot_ix = (frame / 60) % 2;
    base_color = red_and_green[robot_ix];
    font_color = red_and_green[(robot_ix + 1) % 2];
  }

  for (int i = 0; i < _2024_day14_state.robot_length; i++) {
    struct robot * robot = &_2024_day14_state.robot[i];
    draw_robot(robot->x, robot->y, base_color);
  }

  glyph_start(font->texture_width, font->texture_height);

  draw_time(font,
            glyphs);

  if (font_color != 0xffffffff) {
    draw_christmas(font, glyphs,
                   font_color, 50);
    draw_christmas(font, glyphs,
                   font_color, 350);
  }
}
