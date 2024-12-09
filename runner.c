#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "printf.h"
#include "input.h"
#include "runner.h"

typedef int64_t (* part_func)(const char * input, int length);
typedef void (* render_func)(const struct font * font,
                             const struct glyph * glyphs,
                             const void * maple_ft0_data);

struct day_funcs {
  part_func part[2];
  render_func render;
};

#include "runner.inc"
const int solution_days = (sizeof (solution)) / (sizeof (solution[0]));
const int solution_ticks = solution_days * 2;

bool runner_tick(struct runner_state * runner_state)
{
  int tick = (solution_ticks - 1) - runner_state->tick;

  if (tick < 0) {
    runner_state->want_render = false;
    return true;
  }

  int part = tick % 2;
  int day = tick / 2;

  if (day < 8)
    return true;

  runner_state->want_render = solution[day].render != NULL;

  char * buf;
  int length;
  //open_sample(day + 1, part + 1, &buf, &length);
  open_input(day + 1, &buf, &length);
  int64_t answer = solution[day].part[part](buf, length);

  printf("day %d part %d: %l\n", day + 1, part + 1, answer);

  runner_state->tick += 1;

  return false;
}

void runner_render(struct runner_state * runner_state,
                   const struct font * font,
                   const struct glyph * glyphs,
                   const void * maple_ft0_data)
{
  int day = runner_state->tick / 2;

  if (day >= solution_days) {
    return;
  }
  if (solution[day].render != NULL) {
    solution[day].render(font, glyphs, maple_ft0_data);
  }
}
