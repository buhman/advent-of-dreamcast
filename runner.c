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
  int year;
  int day;
  part_func part[2];
  render_func render;
};

#include "runner.inc"
const int solution_days = (sizeof (solution)) / (sizeof (solution[0]));
const int solution_ticks = solution_days * 2;

bool runner_tick(struct runner_state * runner_state)
{
  int tick = (solution_ticks - 1) - runner_state->tick;
  //int tick = runner_state->tick;
  runner_state->tick += 1;

  if (tick < 0) {
    runner_state->want_render = false;
    return true;
  }

  int part = tick % 2;
  int ix = tick / 2;
  int year = solution[ix].year;
  int day = solution[ix].day;

  if (year != 2024 || day != 17) {
    return false;
  }

  runner_state->want_render = solution[ix].render != NULL;
  //printf("want_render %d\n", runner_state->want_render);

  char * buf;
  int length;
  //open_sample(ix, part, &buf, &length);
  open_input(ix, &buf, &length);
  int64_t answer = solution[ix].part[part](buf, length);

  printf("%d day %d part %d: %l\n", year, day, part + 1, answer);

  return false;
}

void runner_render(struct runner_state * runner_state,
                   const struct font * font,
                   const struct glyph * glyphs,
                   const void * maple_ft0_data)
{
  int tick = (solution_ticks - 1) - runner_state->tick;
  int ix = tick / 2;

  if (tick < 0) {
    return;
  }

  if (solution[ix].render != NULL) {
    solution[ix].render(font, glyphs, maple_ft0_data);
  }
}
