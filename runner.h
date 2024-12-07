#pragma once

#include <stdbool.h>

#include "font/font.h"

#ifdef __cplusplus
extern "C" {
#endif

struct runner_state {
  int tick;
  bool want_render;
};

bool runner_tick(struct runner_state * runner_state);
void runner_render(struct runner_state * runner_state,
                   const struct font * font,
                   const struct glyph * glyphs,
                   const void * maple_ft0_data);

#ifdef __cplusplus
}
#endif
