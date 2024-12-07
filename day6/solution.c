#include <stdbool.h>
#include <stddef.h>
#include "printf.h"
#include "parse.h"

#include "solution.h"

static struct position find_guard(const char * input, int length,
                                  int stride)
{
  int x = 0;
  int y = 0;
  for (int i = 0; i < length; i++) {
    if (input[i] == '^') {
      break;
    }
    x += 1;
    if (x >= stride) {
      x = 0;
      y += 1;
    }
  }

  return (struct position){x, y};
}

static bool position_inside_map(int width, int height,
                                int x, int y)
{
  return
    x >= 0     &&
    y >= 0     &&
    x < width  &&
    y < height ;
}

static bool position_contains_obstacle(const char * input,
                                       int stride,
                                       int width, int height,
                                       int x, int y)
{
  if (!position_inside_map(width, height, x, y))
    return false;

  char c = input[y * stride + x];
  return c == '#';
}

static enum facing turn(enum facing facing)
{
  switch (facing) {
  case UP:    return RIGHT;
  case RIGHT: return DOWN;
  case DOWN:  return LEFT;
  case LEFT:  return UP;
  }
  __builtin_unreachable();
}


static struct position move(enum facing facing, int x, int y)
{
  switch (facing) {
  case UP:    return (struct position){x    , y - 1};
  case DOWN:  return (struct position){x    , y + 1};
  case LEFT:  return (struct position){x - 1, y    };
  case RIGHT: return (struct position){x + 1, y    };
  }
  __builtin_unreachable();
}

static void guard_move(struct guard * guard, bool collision)
{
  if (collision) {
    guard->facing = turn(guard->facing);
  } else {
    guard->position = move(guard->facing, guard->position.x, guard->position.y);
  }
}

static bool guard_collision(const char * input,
                            int stride,
                            int width, int height,
                            const struct guard * guard)
{
  struct position position = move(guard->facing, guard->position.x, guard->position.y);

  return position_contains_obstacle(input, stride, width, height, position.x, position.y);
}

static bool guard_collision_obstacle(const char * input,
                                     int stride,
                                     int width, int height,
                                     const struct guard * guard,
                                     struct position obstacle)
{
  struct position position = move(guard->facing, guard->position.x, guard->position.y);

  return (position.x == obstacle.x && position.y == obstacle.y)
      || position_contains_obstacle(input, stride, width, height, position.x, position.y);
}

static int sum(unsigned char * l, int length)
{
  int acc = 0;
  for (int i = 0; i < length; i++) {
    acc += (int)(l[i] > 0);
  }
  return acc;
}

struct solution_state day6_state = {0};

void state_init(int part,
                const char * input,
                int stride,
                int width,
                int height,
                unsigned char * visited,
                struct guard * guard)
{
  day6_state.part = part;
  day6_state.input = input;
  day6_state.stride = stride;
  day6_state.width = width;
  day6_state.height = height;
  day6_state.visited = visited;
  day6_state.guard[0] = guard;
}

int day6_part1(const char * input, int length)
{
  int stride = parse_stride(input, length);
  int height = parse_height(input, length);
  int width = stride - 1;

  unsigned char visited[height * width];
  for (int i = 0; i < width * height; i++) visited[i] = 0;

  struct guard guard;
  guard.facing = UP;
  guard.position = find_guard(input, length, stride);

  state_init(1, input, stride, width, height, visited, &guard);
  while (true) {
    /*
    if (!day6_state.step)
      continue;
    day6_state.step = false;
    */

    bool guard_inside_map = position_inside_map(width, height,
                                                guard.position.x, guard.position.y);
    if (!guard_inside_map)
      break;

    visited[guard.position.y * width + guard.position.x] |= (1 << (int)guard.facing);

    bool collision = guard_collision(input,
                                     stride,
                                     width, height,
                                     &guard);
    guard_move(&guard, collision);
  }

  return sum(visited, height * width);
}

static bool speculative_obstacle_causes_loop(const char * input,
                                             int stride,
                                             int width, int height,
                                             unsigned char * visited,
                                             struct position origin,
                                             struct position obstacle)
{
  // reset visited
  for (int i = 0; i < width * height; i++) visited[i] = 0;

  struct guard guard;
  guard.facing = UP;
  guard.position = origin;

  while (true) {
    bool guard_inside_map = position_inside_map(width, height,
                                                guard.position.x, guard.position.y);
    if (!guard_inside_map)
      break;

    // is this a loop?
    if (visited[guard.position.y * width + guard.position.x] & (1 << (int)guard.facing))
      return true;

    visited[guard.position.y * width + guard.position.x] |= (1 << (int)guard.facing);

    bool collision = guard_collision_obstacle(input,
                                              stride,
                                              width, height,
                                              &guard,
                                              obstacle);
    guard_move(&guard, collision);
  }

  return false;
}

int day6_part2(const char * input, int length)
{
  int stride = parse_stride(input, length);
  int height = parse_height(input, length);
  int width = stride - 1;

  unsigned char visited[height * width];
  for (int i = 0; i < width * height; i++) visited[i] = 0;

  struct position origin = find_guard(input, length, stride);
  struct guard guard;
  guard.facing = UP;
  guard.position = origin;

  state_init(2, input, stride, width, height, visited, &guard);

  unsigned char obstacles[height * width];
  for (int i = 0; i < width * height; i++) obstacles[i] = 0;
  unsigned char loops[height * width];
  for (int i = 0; i < width * height; i++) loops[i] = 0;

  while (true) {
    bool guard_inside_map = position_inside_map(width, height,
                                                guard.position.x, guard.position.y);
    if (!guard_inside_map)
      break;

    bool collision = guard_collision(input,
                                     stride,
                                     width, height,
                                     &guard);

    if (!collision) {
      struct position obstacle = move(guard.facing, guard.position.x, guard.position.y);
      if (obstacles[obstacle.y * width + obstacle.x] == 0) {
        obstacles[obstacle.y * width + obstacle.x] = 1;
        bool loop = speculative_obstacle_causes_loop(input,
                                                     stride,
                                                     width, height,
                                                     visited,
                                                     origin,
                                                     obstacle);
        loops[obstacle.y * width + obstacle.x] |= loop;
      }
    }

    guard_move(&guard, collision);
  }

  return sum(loops, height * width);
}
