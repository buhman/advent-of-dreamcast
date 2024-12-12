#include <stdint.h>

#include "parse.h"
#include "cartesian.h"
#include "printf.h"
#include "memory.h"
#include "array.h"

struct offset {
  int x;
  int y;
};

int walk_trailhead(const char * input,
                   int depth,
                   int stride,
                   int width, int height,
                   int x, int y,
                   char * reachable)
{
  if (depth == 9) {
    reachable[y * width + x] = 1;
    return 1;
  }

  const static struct offset offset[] = {
    { 1,  0},
    {-1,  0},
    { 0,  1},
    { 0, -1},
  };

  int rating = 0;
  for (int i = 0; i < (sizeof (offset)) / (sizeof (offset[0])); i++) {
    int new_x = x + offset[i].x;
    int new_y = y + offset[i].y;
    if (cartesian_inside(width, height, new_x, new_y)) {
      char c = input[new_y * stride + new_x];
      int new_depth = parse_base10_digit(c);
      if (new_depth == depth + 1) {
        rating += walk_trailhead(input,
                                 new_depth,
                                 stride,
                                 width, height,
                                 new_x, new_y,
                                 reachable);
      }
    }
  }

  return rating;
}

struct rating_score {
  int rating;
  int score;
};

struct rating_score find_trailheads(const char * input, int length,
                                    int stride,
                                    int width, int height
                                    )
{
  int x = 0;
  int y = 0;

  char reachable[width * height];
  int total_score = 0;
  int total_rating = 0;

  for (int i = 0; i < length; i++) {
    if (input[i] == '0') {
      memory_set_char(reachable, 0, width * height);
      int rating = walk_trailhead(input, 0, stride, width, height, x, y, reachable);
      total_rating += rating;
      int score = array_sum_char(reachable, width * height);
      total_score += score;
    }
    if (input[i] == '\n') {
      x = 0;
      y += 1;
    } else {
      x += 1;
    }
  }

  return (struct rating_score){total_rating, total_score};
}

int64_t _2024_day10_part1(const char * input, int length)
{
  int stride = parse_stride(input, length);
  int height = parse_height(input, length);
  int width = stride - 1;

  struct rating_score rs = find_trailheads(input, length, stride, width, height);

  return rs.score;
}

int64_t _2024_day10_part2(const char * input, int length)
{
  int stride = parse_stride(input, length);
  int height = parse_height(input, length);
  int width = stride - 1;

  struct rating_score rs = find_trailheads(input, length, stride, width, height);

  return rs.rating;
}
