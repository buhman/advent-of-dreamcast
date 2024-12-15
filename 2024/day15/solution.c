#include <stdint.h>

#include "cartesian.h"
#include "memory.h"
#include "parse.h"
#include "printf.h"

static bool move(char * map,
                 int width, int height,
                 int x, int y,
                 enum cartesian_direction direction,
                 bool commit)
{
  const struct cartesian_neighbor * dir = &cartesian_neighbor[direction];

  int nx = x + dir->x;
  int ny = y + dir->y;
  char n = map[ny * width + nx];
  switch (n) {
  case '#':
    return false;
  case 'O':
    if (!move(map, width, height, nx, ny, direction, false))
      return false;
    move(map, width, height, nx, ny, direction, commit);
    break;
  case '[': [[fallthrough]];
  case ']':
    {
      int nxoff = (n == '[') ? 1 : -1;

      bool move2 = true;
      if (direction == CARTESIAN_UP || direction == CARTESIAN_DOWN)
        move2 = move(map, width, height, nx + nxoff, ny, direction, false);

      bool move1 = move(map, width, height, nx, ny, direction, false);

      if (!move1 || !move2)
        return false;

      if (direction == CARTESIAN_UP || direction == CARTESIAN_DOWN)
        move(map, width, height, nx + nxoff, ny, direction, commit);

      move(map, width, height, nx, ny, direction, commit);

      break;
    }
  }

  if (commit) {
    char c = map[y * width + x];
    map[y * width + x] = '.';
    map[ny * width + nx] = c;
  }

  return true;
}

static enum cartesian_direction parse_direction(char c)
{
  switch (c) {
  case '<': return CARTESIAN_LEFT;
  case '>': return CARTESIAN_RIGHT;
  case '^': return CARTESIAN_UP;
  case 'v': return CARTESIAN_DOWN;
  }
  return -1;
}

typedef int (* map_transform_func)(char * map, char c);

static int part1_map_transform(char * map, char c)
{
  *map = c;
  return 1;
}

static int part2_map_transform(char * map, char c)
{
  switch (c) {
  case '#': map[0] = '#'; map[1] = '#'; break;
  case '.': map[0] = '.'; map[1] = '.'; break;
  case 'O': map[0] = '['; map[1] = ']'; break;
  case '@': map[0] = '@'; map[1] = '.'; break;
  };
  return 2;
}

static const char * parse_map(const char * input, const char * end,
                              int * width, int * height,
                              int * x, int * y,
                              char * map,
                              map_transform_func func)
{
  *width = 0;
  *height = 0;

  while (input < end) {
    if (input[0] == '\n' && input[1] == '\n') {
      *height += 1;
      input = parse_skip(input, '\n');
      return input;
    } else if (*input == '\n') {
      *height += 1;
      *width = 0;
      input = parse_skip(input, '\n');
    } else {
      if (*input == '@') {
        *x = *width;
        *y = *height;
      }
      int char_width = func(map, *input++);
      *width += char_width;
      map += char_width;
    }
  }

  return input;
}

static void print_map(const char * map,
                      int width, int height)
{
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      print_char(map[y * width + x]);
    }
    print_char('\n');
  }
  print_char('\n');
}

static int gps_coordinate(int x, int y)
{
  return 100 * y + x;
}

static int sum_boxes(const char * map, int width, int height)
{
  int sum = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      char c = map[y * width + x];
      if (c == 'O' || c == '[') {
        sum += gps_coordinate(x, y);
      }
    }
  }
  return sum;
}

static int solve(const char * input, int length,
                 map_transform_func func)
{
  const char * end = input + length;

  int width;
  int height;
  int x;
  int y;
  char map[100 * 100];
  input = parse_map(input, end,
                    &width, &height,
                    &x, &y,
                    map,
                    func);
  const char * movements = input;
  while (movements < end) {
    char c = *movements++;
    enum cartesian_direction direction = parse_direction(c);
    if (move(map, width, height, x, y, direction, true)) {
      x += cartesian_neighbor[direction].x;
      y += cartesian_neighbor[direction].y;
    }

    movements = parse_skip(movements, '\n');
  }

  return sum_boxes(map, width, height);
}

int64_t _2024_day15_part1(const char * input, int length)
{
  return solve(input, length, part1_map_transform);
}

int64_t _2024_day15_part2(const char * input, int length)
{
  return solve(input, length, part2_map_transform);
}
