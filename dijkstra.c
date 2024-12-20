#include "cartesian.h"
#include "dijkstra.h"
#include "heap.h"
#include "memory.h"
#include "printf.h"

//#include <stdio.h>
//#include <assert.h>

void dijkstra_cartesian(const char * graph,
                        int stride,
                        int width, int height,
                        int start_x, int start_y,
                        int end_x, int end_y,
                        char wall,
                        struct dijkstra_xy16 * prev,
                        int * dist)
{
  struct heap_entry queue[width * height / 2 + 1];
  int queue_length = 0;

  // initialize all distances to the maximum distance
  memory_set_int(dist, 0x7fffffff, width * height);
  // initialize the distance from the start to the start to zero
  dist[start_y * width + start_x] = 0;

  // initialize the all node paths to "unknown"
  memory_set_int((int *)prev, -1, width * height);
  prev[start_y * width + start_x] =
    (struct dijkstra_xy16){start_x - 1, start_y}; // west

  // initialize the queue with "start"
  heap_append_xy(queue, &queue_length, 0, start_x, start_y);

  while (queue_length > 0) {
    struct heap_entry min = heap_extract_max(queue, &queue_length);
    //if (min.x == end_x && min.y == end_y)
    //return;
    for (int i = 0; i < 4; i++) {
      int nx = min.x + cartesian_neighbor[i].x;
      int ny = min.y + cartesian_neighbor[i].y;
      if (!cartesian_inside(width, height, nx, ny))
        continue;
      if (graph[ny * stride + nx] == wall)
        continue;
      //if (prev[ny * width + nx].x != -1)
      //continue;
      int turn = 0;
      struct dijkstra_xy16 * xy = &prev[min.y * width + min.x];
      int dx = min.x - xy->x;
      int dy = min.y - xy->y;
      if (min.y == 137) {
        printf("xy % 2d % 2d pxy % 2d % 2d nxy % 2d % 2d dist %d\n",
               min.x, min.y,
               xy->x, xy->y,
               nx, ny,
               dist[min.y * width + min.x]);
      }
      if (cartesian_neighbor[i].x != dx || cartesian_neighbor[i].y != dy)
        turn = 1000;

      int alt = dist[min.y * width + min.x] + 1 + turn;
      if (alt < dist[ny * width + nx]) {
        prev[ny * width + nx] = (struct dijkstra_xy16){min.x, min.y};
        dist[ny * width + nx] = alt;
        heap_append_xy(queue, &queue_length, -alt, nx, ny);
      }
    }
  }
}
