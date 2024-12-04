#include <stdbool.h>

#include "printf.h"

static int parse_stride(char * input, int length)
{
  for (int i = 0; i < length; i++) {
    if (input[i] == '\n') {
      return i + 1;
    }
  }
  return -1;
}

static int parse_height(char * input, int length)
{
  int rows = 0;
  int i;
  for (i = 0; i < length; i++) {
    if (input[i] == '\n') {
      rows += 1;
    }
  }
  if (input[i-1] != '\n') {
    rows += 1;
  }
  return rows;
}

enum offset_type {
  N,
  S,
  E,
  W,
  NE,
  NW,
  SE,
  SW,
};

static char offsets[][2] = {
  [N ] = { 0, -1},
  [S ] = { 0,  1},
  [E ] = { 1,  0},
  [W ] = {-1,  0},
  [NE] = { 1, -1},
  [NW] = {-1, -1},
  [SW] = {-1,  1},
  [SE] = { 1,  1},
};

static bool xy_inside(int width, int height,
                      int x, int y)
{
  if (y < 0 || x < 0)
    return false;
  if (x >= width)
    return false;
  if (y >= height)
    return false;
  return true;
}

static char get_char(char * input,
                     int stride,
                     int x, int y)
{
  int ix = y * stride + x;
  return input[ix];
}

static bool offset_match(char * input,
                         int stride,
                         int width, int height,
                         int x, int y,
                         char * offset,
                         const char * str,
                         int str_length)
{
  for (int i = 0; i < str_length; i++) {
    if (!xy_inside(width, height, x, y))
      return false;

    char c = get_char(input, stride, x, y);
    if (c != str[i])
      return false;

    x += offset[0];
    y += offset[1];
  }

  return true;
}

static bool offset_match_centered(char * input,
                                  int stride,
                                  int width, int height,
                                  int x, int y,
                                  char * offset,
                                  const char * str,
                                  int str_length)
{
  // blindly assumes odd-numbered str_length
  // distance from the corner to the center
  int center = str_length / 2; // floor division

  // go to corner
  x -= offset[0] * center;
  y -= offset[1] * center;

  return offset_match(input,
                      stride,
                      width, height,
                      x, y,
                      offset,
                      str,
                      str_length);
}

static bool offset_match_cross(char * input,
                               int stride,
                               int width, int height,
                               int x, int y,
                               char * offset,
                               const char * str,
                               int str_length)
{
  bool match0 = offset_match_centered(input,
                                      stride,
                                      width, height,
                                      x, y,
                                      offset,
                                      str,
                                      str_length);
  if (!match0)
    return false;

  char cross1[2] = {-offset[0],  offset[1]};
  char cross2[2] = { offset[0], -offset[1]};

  bool match1 = offset_match_centered(input,
                                      stride,
                                      width, height,
                                      x, y,
                                      cross1,
                                      str,
                                      str_length);
  bool match2 = offset_match_centered(input,
                                      stride,
                                      width, height,
                                      x, y,
                                      cross2,
                                      str,
                                      str_length);
  return match1 || match2;
}

int day4_part1(char * input, int length)
{
  int stride = parse_stride(input, length);
  int height = parse_height(input, length);
  int width = stride - 1;

  const char * str = "XMAS";
  int str_length = 4;

  int match_count = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      for (int o = 0; o < 8; o++) {
        bool match = offset_match(input,
                                  stride,
                                  width, height,
                                  x, y,
                                  offsets[o],
                                  str,
                                  str_length);
        match_count += (int)match;
      }
    }
  }

  return match_count;
}

int day4_part2(char * input, int length)
{
  int stride = parse_stride(input, length);
  int height = parse_height(input, length);
  int width = stride - 1;

  const char * str = "MAS";
  int str_length = 3;

  int match_count = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      bool match_ne = offset_match_cross(input,
                                         stride,
                                         width, height,
                                         x, y,
                                         offsets[NE],
                                         str,
                                         str_length);
      bool match_sw = offset_match_cross(input,
                                         stride,
                                         width, height,
                                         x, y,
                                         offsets[SW],
                                         str,
                                         str_length);
      match_count += (int)(match_ne || match_sw);
    }
  }

  return match_count;
}
