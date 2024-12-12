#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct position {
  int x;
  int y;
};

enum facing {
  UP,
  RIGHT,
  DOWN,
  LEFT,
};

struct guard {
  struct position position;
  enum facing facing;
};

struct solution_state {
  bool step;
  int part;
  const char * input;
  int stride;
  int width;
  int height;
  struct guard * guard[2];
  unsigned char * visited;
};

#ifdef __cplusplus
}
#endif
