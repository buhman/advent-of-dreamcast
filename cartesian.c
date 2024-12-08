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
