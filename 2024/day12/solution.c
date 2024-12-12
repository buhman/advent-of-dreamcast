#include <stdint.h>

#include "cartesian.h"
#include "parse.h"
#include "printf.h"
#include "memory.h"
#include "abs.h"
#include "minmax.h"

struct perimeter_area_sides {
  int perimeter;
  int area;
  int sides;
};

struct origin_entry {
  enum cartesian_direction direction;
  int x;
  int y;
};

struct side_origin {
  struct origin_entry origins[512];
  int length;
};

static bool walk_to_side_origin(const char * input,
                                int stride,
                                int width, int height,
                                int x, int y,
                                struct side_origin * side_origin,
                                enum cartesian_direction perimeter_direction)
{
  static enum cartesian_direction walk_from_perimeter[] = {
    [CARTESIAN_RIGHT] = CARTESIAN_UP,
    [CARTESIAN_LEFT ] = CARTESIAN_UP,
    [CARTESIAN_DOWN ] = CARTESIAN_LEFT,
    [CARTESIAN_UP   ] = CARTESIAN_LEFT,
  };
  enum cartesian_direction walk_direction = walk_from_perimeter[perimeter_direction];

  char c = input[y * stride + x];

  while (true) {
    int walk_x = x + cartesian_neighbor[walk_direction].x;
    int walk_y = y + cartesian_neighbor[walk_direction].y;

    char wc = input[walk_y * stride + walk_x];

    // walked into another shape
    if (!cartesian_inside(width, height, walk_x, walk_y) || wc != c)
      break;

    int nx = walk_x + cartesian_neighbor[perimeter_direction].x;
    int ny = walk_y + cartesian_neighbor[perimeter_direction].y;

    char nc = input[ny * stride + nx];

    if (!cartesian_inside(width, height, nx, ny) || c != nc) {
      x = walk_x;
      y = walk_y;
    } else {
      break;
    }
  }

  for (int i = 0; i < side_origin->length; i++) {
    struct origin_entry * origin = &side_origin->origins[i];
    if (origin->x == x && origin->y == y && origin->direction == perimeter_direction) {
      // not a new side
      return false;
    }
  }
  // add the new side
  struct origin_entry * origin = &side_origin->origins[side_origin->length++];
  origin->x = x;
  origin->y = y;
  origin->direction = perimeter_direction;
  return true;
}

static struct perimeter_area_sides flood_fill(const char * input,
                                              int stride,
                                              int width, int height,
                                              int x, int y,
                                              char * visited,
                                              struct side_origin * side_origin)
{
  int perimeter = 0;
  int area = 1;
  int sides = 0;

  visited[y * width + x] = 1;

  for (int i = 0; i < cartesian_neighbor_count; i++) {
    int nx = x + cartesian_neighbor[i].x;
    int ny = y + cartesian_neighbor[i].y;

    char c = input[y * stride + x];
    char nc = input[ny * stride + nx];

    if (!cartesian_inside(width, height, nx, ny) || c != nc) {
      perimeter += 1;
      bool new_side = walk_to_side_origin(input,
                                          stride,
                                          width, height,
                                          x, y,
                                          side_origin,
                                          i);
      sides += (int)new_side;

    } else {
      if (!visited[ny * width + nx]) {
        struct perimeter_area_sides npas = flood_fill(input,
                                                      stride,
                                                      width, height,
                                                      nx, ny,
                                                      visited,
                                                      side_origin);
        perimeter += npas.perimeter;
        area += npas.area;
        sides += npas.sides;
      }
    }
  }

  return (struct perimeter_area_sides){perimeter, area, sides};
}

typedef int (* part_func)(int perimeter, int area, int sides);

static int solve(const char * input, int length, part_func func)
{
  int stride = parse_stride(input, length);
  int height = parse_height(input, length);
  int width = stride - 1;
  char visited[width * height];
  memory_set_char(visited, 0, (sizeof (visited)) / (sizeof (visited[0])));
  struct side_origin side_origin;

  int sum = 0;

  int x = 0;
  int y = 0;
  for (int ix = 0; ix < length; ix++) {
    if (x == stride - 1) {
      x = 0;
      y += 1;
      continue;
    }

    if (!visited[y * width + x]) {
      side_origin.length = 0;
      struct perimeter_area_sides npas = flood_fill(input,
                                                    stride,
                                                    width, height,
                                                    x, y,
                                                    visited,
                                                    &side_origin);

      sum += func(npas.perimeter, npas.area, npas.sides);
    }
    x += 1;
  }
  return sum;
}

static int part1_sum(int perimeter, int area, int sides)
{
  return perimeter * area;
}

static int part2_sum(int perimeter, int area, int sides)
{
  return area * sides;
}

int64_t _2024_day12_part1(const char * input, int length)
{
  return solve(input, length, part1_sum);
}

int64_t _2024_day12_part2(const char * input, int length)
{
  return solve(input, length, part2_sum);
}
