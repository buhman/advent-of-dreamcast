#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void bfs(const char * graph,
         int stride,
         int width, int height,
         int start_x, int start_y,
         char wall,
         struct cartesian_link * path);

struct bfs_cartesian_link {
  int16_t parent_x;
  int16_t parent_y;
};

#ifdef __cplusplus
}
#endif
