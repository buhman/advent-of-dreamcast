#pragma once

#ifdef __cplusplus
extern "C" {
#endif

bool cartesian_inside(int width, int height,
                      int x, int y);

struct cartesian_neighbor {
  int x;
  int y;
};

enum cartesian_direction {
  CARTESIAN_RIGHT,
  CARTESIAN_LEFT,
  CARTESIAN_DOWN,
  CARTESIAN_UP,
  CARTESIAN_RIGHTDOWN,
  CARTESIAN_RIGHTUP,
  CARTESIAN_LEFTDOWN,
  CARTESIAN_LEFTUP,
};

extern const struct cartesian_neighbor cartesian_neighbor[4];

#define cartesian_neighbor_count ((sizeof (cartesian_neighbor)) / (sizeof (cartesian_neighbor[0])))

extern const struct cartesian_neighbor cartesian_diagonal_neighbor[8];

#define cartesian_diagonal_neighbor_count ((sizeof (cartesian_diagonal_neighbor)) / (sizeof (cartesian_diagonal_neighbor[0])))

#ifdef __cplusplus
}
#endif
