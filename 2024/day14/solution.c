#include <stdint.h>

#include "parse.h"
#include "printf.h"
#include "memory.h"

#include "solution.h"
#include "cartesian.h"

struct solution_state _2024_day14_state = {0};

const char * parse_robot(const char * input, struct robot * robot)
{
  input = parse_match(input, "p=");
  input = parse_base10(input, &robot->x);
  input = parse_skip(input, ',');
  input = parse_base10(input, &robot->y);
  input = parse_match(input, " v=");
  input = parse_base10(input, &robot->dx);
  input = parse_skip(input, ',');
  input = parse_base10(input, &robot->dy);
  input = parse_skip(input, '\n');
  return input;
}

static inline int positive_modulus(int n, int d) {
    return (n % d + d) % d;
}

void simulate_robot(struct robot * robot,
                    int width, int height,
                    int steps)
{
  int x = robot->x + robot->dx * steps;
  robot->x = positive_modulus(x, width);

  int y = robot->y + robot->dy * steps;
  robot->y = positive_modulus(y, height);
}

static int xy_to_quadrant(int x, int y, int width, int height)
{
  int midx = width / 2;
  int midy = height / 2;

  if (x == midx || y == midy)
    return -1;

  return
    (0b01 * (x > midx)) |
    (0b10 * (y > midy));
}


static int flood_fill(char * visited,
                      int width, int height,
                      int x, int y)
{
  int size = 1;

  visited[y * width + x] = 0;

  for (int i = 0; i < cartesian_neighbor_count; i++) {
    int nx = x + cartesian_neighbor[i].x;
    int ny = y + cartesian_neighbor[i].y;

    char nc = visited[ny * width + nx];

    if (cartesian_inside(width, height, nx, ny) && nc != 0) {
      size += flood_fill(visited,
                         width, height,
                         nx, ny);
    }
  }

  return size;
}

int64_t _2024_day14_part1(const char * input, int length)
{
  const char * end = input + length;

  //int width = 11;
  //int height = 7;
  int width = 101;
  int height = 103;
  int steps = 100;

  int quadrant[4];
  memory_set_int(quadrant, 0, 4);

  while (input < end) {
    struct robot robot;

    input = parse_robot(input, &robot);
    simulate_robot(&robot, width, height, steps);

    int ix = xy_to_quadrant(robot.x, robot.y, width, height);
    if (ix >= 0)
      quadrant[ix] += 1;
  }

  int sum = quadrant[0];
  for (int i = 1; i < 4; i++)
    sum *= quadrant[i];

  return sum;
}

int64_t _2024_day14_part2(const char * input, int length)
{
  const char * end = input + length;

  //int width = 11;
  //int height = 7;
  int width = 101;
  int height = 103;

  int robot_length = parse_height(input, length);
  struct robot robot[robot_length];

  _2024_day14_state.time = 0;
  _2024_day14_state.robot = &robot[0];
  _2024_day14_state.robot_length = robot_length;

  int i = 0;
  while (input < end) {
    input = parse_robot(input, &robot[i++]);
  }

  _2024_day14_state.time = 0;

  char visited[width * height];

  int max_size = 0;
  _2024_day14_state.max_size = max_size;

  while (max_size < 200) {
    int step = _2024_day14_state.step;
    if (step == 0)
      continue;

    _2024_day14_state.time += step;

    memory_set_char(visited, 0, width * height);

    for (int i = 0; i < robot_length; i++) {
      simulate_robot(&robot[i], width, height, step);
      visited[robot[i].y * width + robot[i].x] = 1;
    }

    for (int i = 0; i < robot_length; i++) {
      if (visited[robot[i].y * width + robot[i].x]) {
        int size = flood_fill(visited,
                              width, height,
                              robot[i].x, robot[i].y);
        _2024_day14_state.size = size;
        if (size > max_size) {
          max_size = size;
          _2024_day14_state.max_size = max_size;
        }
        if (size > 200)
          _2024_day14_state.step = 0;
      }
    }
  }

  return _2024_day14_state.time;
}
