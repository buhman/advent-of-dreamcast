#include <stdbool.h>
#include <stddef.h>

#include "printf.h"
#include "input.h"
#include "runner.h"

typedef int (* part_func)(const char * input, int length);
typedef void (* render_func)(const struct font * font,
                             const struct glyph * glyphs,
                             const void * maple_ft0_data);

struct day_funcs {
  part_func part[2];
  render_func render;
};

#include "runner.inc"
const int solution_days = (sizeof (solution)) / (sizeof (solution[0]));

bool runner_tick(struct runner_state * runner_state)
{
  int part = runner_state->tick % 2;
  int day = runner_state->tick / 2;

  if (day >= solution_days) {
    runner_state->want_render = false;
    return true;
  }

  runner_state->want_render = solution[day].render != NULL;

  char * buf;
  int length;
  //open_sample(day + 1, part + 1, &buf, &length);
  open_input(day + 1, &buf, &length);
  int answer = solution[day].part[part](buf, length);

  printf("day %d part %d: %d\n", day + 1, part + 1, answer);

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
