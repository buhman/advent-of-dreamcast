#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct dijkstra_xy16 {
  int16_t x;
  int16_t y;
};

void dijkstra_cartesian(const char * graph,
                        int stride,
                        int width, int height,
                        int start_x, int start_y,
                        int end_x, int end_y,
                        char wall,
                        struct dijkstra_xy16 * prev,
                        int * dist);

#ifdef __cplusplus
}
#endif
