#include <stdbool.h>

#include "cartesian.h"

bool cartesian_inside(int width, int height,
                      int x, int y)
{
  return
    x >= 0     &&
    y >= 0     &&
    x < width  &&
    y < height ;
}

const struct cartesian_neighbor cartesian_neighbor[4] = {
  [CARTESIAN_RIGHT] = { 1,  0},
  [CARTESIAN_LEFT ] = {-1,  0},
  [CARTESIAN_DOWN ] = { 0,  1},
  [CARTESIAN_UP   ] = { 0, -1},
};
