#include <stdint.h>

#include "parse.h"
#include "printf.h"

enum cube_color {
  red   = 0,
  green = 1,
  blue  = 2,
};

struct cube_set {
  int color[3];
};

static const char * parse_color(const char * input, enum cube_color * color)
{
  const char * end;
  if ((end = parse_match(input, "red"))) {
    *color = red;
  } else if ((end = parse_match(input, "blue"))) {
    *color = blue;
  } else if ((end = parse_match(input, "green"))) {
    *color = green;
  }
  return end;
}

static const char * parse_cube(const char * input, int * value, enum cube_color * color)
{
  input = parse_skip(input, ' ');
  input = parse_base10(input, value);
  input = parse_skip(input, ' ');
  input = parse_color(input, color);
  return input;
}

static const char * parse_game(const char * input, int * number)
{
  input = parse_match(input, "Game ");
  input = parse_base10(input, number);
  input = parse_skip(input, ':');

  return input;
}

static const char * parse_round(const char * input, struct cube_set * set)
{
  while (true) {
    int value;
    enum cube_color color;
    input = parse_cube(input, &value, &color);
    set->color[color] = value;
    if (*input != ',')
      break;
    input++;
  }
  return input;
}

static void part1_set(const struct cube_set * set, void * data)
{
  bool * valid = data;
  bool v = set->color[red] <= 12 && set->color[green] <= 13 && set->color[blue] <= 14;
  *valid &= v;
}

static int part1_sum(int game_number, void * data)
{
  bool * valid = data;
  int res = ((int)*valid) * game_number;
  *valid = true;
  return res;
}

static void part2_set(const struct cube_set * set, void * data)
{
  struct cube_set * max_set = data;
  if (max_set->color[red] < set->color[red])
    max_set->color[red] = set->color[red];
  if (max_set->color[green] < set->color[green])
    max_set->color[green] = set->color[green];
  if (max_set->color[blue] < set->color[blue])
    max_set->color[blue] = set->color[blue];
}

static int part2_sum(int game_number, void * data)
{
  struct cube_set * set = data;
  int res = set->color[red] * set->color[green] * set->color[blue];
  set->color[red] = 0; set->color[green] = 0; set->color[blue] = 0;
  return res;
}

typedef void (* part_set_func)(const struct cube_set * set, void * data);
typedef int (* part_sum_func)(int game_number, void * data);

static int solve(const char * input, int length, part_set_func part_set, part_sum_func part_sum, void * data)
{
  const char * end = input + length;

  int game_number;

  int sum = 0;

  while (input < end) {
    input = parse_game(input, &game_number);

    struct cube_set set;

    while (true) {
      set.color[red] = 0; set.color[green] = 0; set.color[blue] = 0;
      input = parse_round(input, &set);

      part_set(&set, data);

      if (*input != ';')
        break;
      input++;
    }

    int next_sum = sum + part_sum(game_number, data);
    if (next_sum < sum)
      printf("overflow\n");
    sum = next_sum;

    input = parse_skip(input, '\n');
  }

  return sum;
}

int64_t _2023_day2_part1(const char * input, int length)
{
  bool valid = true;

  return solve(input, length, part1_set, part1_sum, (void *)&valid);
}

int64_t _2023_day2_part2(const char * input, int length)
{
  struct cube_set set;
  set.color[red] = 0; set.color[green] = 0; set.color[blue] = 0;

  return solve(input, length, part2_set, part2_sum, (void *)&set);
}
