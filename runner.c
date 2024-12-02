#include <stdbool.h>

#include "printf.h"
#include "input.h"
#include "runner.h"

int day1_part1(char * input, int length);
int day1_part2(char * input, int length);
int day2_part1(char * input, int length);
int day2_part2(char * input, int length);

typedef int (* part_func)(char * input, int length);

part_func solution[][2] = {
  {day1_part1, day1_part2},
  {day2_part1, day2_part2},
};
const int solution_days = (sizeof (solution)) / (sizeof (solution[0]));

bool runner_tick(struct runner_state * runner_state)
{
  int part = runner_state->tick % 2;
  int day = runner_state->tick / 2;

  if (day >= solution_days)
    return true;

  char * buf;
  int length;
  //open_sample(day + 1, part + 1, &buf, &length);
  open_input(day + 1, &buf, &length);
  int answer = solution[day][part](buf, length);

  printf("day %d part %d: %d\n", day + 1, part + 1, answer);

  runner_state->tick += 1;

  return false;
}
