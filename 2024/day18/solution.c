#include <stdint.h>

#include "parse.h"
#include "dijkstra.h"
#include "memory.h"
#include "printf.h"

struct coordinate {
  int x;
  int y;
};

static const char * parse_coordinate(const char * input, struct coordinate * c)
{
  input = parse_base10(input, &c->x);
  input = parse_skip(input, ',');
  input = parse_base10(input, &c->y);
  input = parse_skip(input, '\n');
  return input;
}

static char map_char(const char c)
{
  if (c == 0)
    return '.';
  else if (c == 1)
    return '#';
  else
    return 'O';
}

static void print_map(const char * map, int stride)
{
  for (int y = 0; y < stride; y++) {
    for (int x = 0; x < stride; x++) {

      print_char(map_char(map[y * stride + x]));
    }
    print_char('\n');
  }
}

int64_t _2024_day18_part1(const char * input, int length)
{
  const char * end = input + length;

  struct coordinate start_c = {0, 0};
  //struct coordinate end_c = {6, 6};
  struct coordinate end_c = {70, 70};
  //int stride = 7;
  int stride = 71;

  char map[stride * stride];
  memory_set_char(map, 0, stride * stride);

  int i = 0;
  while (input < end) {
    if (i >= 1024)
      break;
    struct coordinate c;
    input = parse_coordinate(input, &c);

    map[c.y * stride + c.x] = 1;
    i++;
  }

  struct dijkstra_xy16 prev[stride * stride];
  int dist[stride * stride];
  int wall = 1;
  int turn_cost = 0;
  dijkstra_cartesian(map,
                     stride,
                     stride, stride,
                     start_c.x, start_c.y,
                     end_c.x, end_c.y,
                     wall,
                     turn_cost,
                     prev,
                     dist);

  /*
  int x = end_c.x;
  int y = end_c.y;
  while (!(x == start_c.x && y == start_c.y)) {
    struct dijkstra_xy16 * xy = &prev[y * stride + x];
    map[xy->y * stride + xy->x] = 2;
    x = xy->x;
    y = xy->y;
  }
  print_map(map, stride);
  */

  return dist[end_c.y * stride + end_c.x];
}

int64_t _2024_day18_part2(const char * input, int length)
{
  const char * end = input + length;

  struct coordinate start_c = {0, 0};
  //struct coordinate end_c = {6, 6};
  struct coordinate end_c = {70, 70};
  //int stride = 7;
  int stride = 71;

  char map[stride * stride];
  memory_set_char(map, 0, stride * stride);

  int i = 0;
  struct coordinate c;
  while (input < end) {
    input = parse_coordinate(input, &c);

    map[c.y * stride + c.x] = 1;
    i++;

    if (i > 2900) {
      printf("%d ", i);
      struct dijkstra_xy16 prev[stride * stride];
      int dist[stride * stride];
      int wall = 1;
      int turn_cost = 0;
      dijkstra_cartesian(map,
                         stride,
                         stride, stride,
                         start_c.x, start_c.y,
                         end_c.x, end_c.y,
                         wall,
                         turn_cost,
                         prev,
                         dist);

      if (prev[end_c.y * stride + end_c.x].x == -1)
        break;
    }
  }

  printf("\n%d,%d\n", c.x, c.y);

  return -1;
}
