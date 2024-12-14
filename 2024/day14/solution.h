#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct robot {
  int x;
  int y;
  int dx;
  int dy;
};

struct solution_state {
  int step;
  int time;
  int max_size;
  int size;
  struct robot * robot;
  int robot_length;
};

extern struct solution_state _2024_day14_state;

#ifdef __cplusplus
}
#endif
