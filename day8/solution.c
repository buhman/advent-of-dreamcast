#include <stdint.h>

#include "parse.h"
#include "printf.h"
#include "cartesian.h"
#include "array.h"

struct position {
  char x;
  char y;
};

struct antenna {
  struct position position[8];
  char count;
};

#define FIRST_ANTENNA '0'
#define LAST_ANTENNA 'z'
#define ANTENNA_TYPES ((LAST_ANTENNA - FIRST_ANTENNA) + 1)

void parse_antennas(const char * input, int length, struct antenna * antennas)
{
  int x = 0;
  int y = 0;
  for (int i = 0; i < length; i++) {
    char c = input[i];
    if (c >= FIRST_ANTENNA && c <= LAST_ANTENNA) {
      struct antenna * ant = &antennas[c - FIRST_ANTENNA];
      ant->position[ant->count++] = (struct position){x, y};
    }
    if (c == '\n') {
      x = 0;
      y += 1;
    } else {
      x += 1;
    }
  }
}

struct position vector(struct position a, struct position b)
{
  return (struct position){b.x - a.x, b.y - a.y};
}

void part1_antinodes(int width, int height,
                     struct position p1, struct position p2,
                     char * antinodes)
{
  struct position slope = vector(p1, p2);

  struct position a[2] = {
    {
      p1.x - slope.x,
      p1.y - slope.y,
    },
    {
      p2.x + slope.x,
      p2.y + slope.y,
    }
  };

  for (int k = 0; k < 2; k++) {
    if (cartesian_inside(width, height, a[k].x, a[k].y)) {
      antinodes[a[k].y * width + a[k].x] = 1;
    }
  }
}

void interpolate_antinodes(int width,
                           int height,
                           struct position ant,
                           struct position slope,
                           char * antinodes)
{
  int x = ant.x;
  int y = ant.y;
  while (true) {
    if (!cartesian_inside(width, height, x, y))
      break;

    antinodes[y * width + x] = 1;

    x -= slope.x;
    y -= slope.y;
  }
}

void part2_antinodes(int width, int height,
                     struct position p1, struct position p2,
                     char * antinodes)
{
  struct position slope = vector(p1, p2);

  interpolate_antinodes(width, height, p1, (struct position){-slope.x, -slope.y}, antinodes);
  interpolate_antinodes(width, height, p2, (struct position){ slope.x,  slope.y}, antinodes);
}

typedef void (* part_solver)(int width, int height,
                             struct position p1, struct position p2,
                             char * antinodes);

void find_antinodes(int width, int height,
                    const struct antenna * antennas,
                    char * antinodes,
                    part_solver func)
{
  for (int t = FIRST_ANTENNA; t <= LAST_ANTENNA; t++) {
    const struct antenna * ant = &antennas[t - FIRST_ANTENNA];
    for (int i = 0; i < ant->count; i++) {
      for (int j = i + 1; j < ant->count; j++) {
        func(width, height,
             ant->position[i], ant->position[j],
             antinodes);
      }
    }
  }
}

int64_t day8_part1(const char * input, int length)
{
  int stride = parse_stride(input, length);
  int height = parse_height(input, length);
  int width = stride - 1;

  struct antenna antennas[ANTENNA_TYPES];
  for (int i = 0; i < ANTENNA_TYPES; i++)
    antennas[i].count = 0;
  char antinodes[width * height];
  for (int i = 0; i < width * height; i++)
    antinodes[i] = 0;

  parse_antennas(input, length, antennas);

  find_antinodes(width, height, antennas, antinodes, part1_antinodes);

  return array_sum_char(antinodes, width * height);
}

int64_t day8_part2(const char * input, int length)
{
  int stride = parse_stride(input, length);
  int height = parse_height(input, length);
  int width = stride - 1;

  struct antenna antennas[ANTENNA_TYPES];
  for (int i = 0; i < ANTENNA_TYPES; i++)
    antennas[i].count = 0;
  char antinodes[width * height];
  for (int i = 0; i < width * height; i++)
    antinodes[i] = 0;

  parse_antennas(input, length, antennas);

  find_antinodes(width, height, antennas, antinodes, part2_antinodes);

  return array_sum_char(antinodes, width * height);
}
