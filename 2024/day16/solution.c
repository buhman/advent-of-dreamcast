#include <stdint.h>

//#include <stdio.h>
#include "printf.h"
#include "dijkstra.h"
#include "memory.h"

static void parse_sewh(const char * input, int length,
                       int * stride,
                       int * width, int * height,
                       int * start_x, int * start_y,
                       int * end_x, int * end_y
                       )
{
  const char * end = input + length;

  *width = 0;
  *height = 0;

  while (input < end) {
    char c = *input++;

    switch (c) {
    case 'S':
      *start_x = *width;
      *start_y = *height;
      break;
    case 'E':
      *end_x = *width;
      *end_y = *height;
      break;
    }

    *width += 1;

    if (c == '\n') {
      *stride = *width;
      *width = 0;
      *height += 1;
      continue;
    }
  }

  *width = *stride - 1;
}

int64_t _2024_day16_part1(const char * input, int length)
{
  int stride;
  int width;
  int height;
  int start_x;
  int start_y;
  int end_x;
  int end_y;

  parse_sewh(input, length,
             &stride,
             &width, &height,
             &start_x, &start_y,
             &end_x, &end_y
             );

  struct dijkstra_xy16 prev[width * height];
  int dist[width * height];

  dijkstra_cartesian(input,
                     stride,
                     width, height,
                     start_x, start_y,
                     end_x, end_y,
                     '#',
                     prev,
                     dist);

  char map[stride * height + 1];
  memory_copy_char(input, stride * height, map);

  int x = end_x;
  int y = end_y;
  while (!(x == start_x && y == start_y)) {
    struct dijkstra_xy16 * xy = &prev[y * width + x];
    map[xy->y * stride + xy->x] = 'x';
    x = xy->x;
    y = xy->y;
  }
  map[stride * height] = 0;
  printf("%s", map);

  return dist[end_y * width + end_x];
}

int64_t _2024_day16_part2(const char * input, int length)
{
  return -1;
}

/*
#include <assert.h>

int main()
{
  FILE * f = fopen("2024/day16/input.txt", "rb");
  const int length = 20022;
  char buf[length];
  size_t len = fread(buf, 1, length, f);
  assert(len == length);
  fclose(f);
  printf("%ld\n", _2024_day16_part1(buf, length));
}
*/
