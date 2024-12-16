#include "cartesian.h"
#include "dijkstra.h"
#include "heap.h"
#include "memory.h"

void dijkstra_cartesian(char * graph,
                        int stride,
                        int width, int height,
                        int source_x, int source_y,
                        int dest_x, int dest_y,
                        char wall)
{
  struct heap_entry queue[width * height / 2 + 1];
  int queue_length = 0;

  // distance from source
  int dist[width * height];
  // initialize all distances to the maximum distance
  memory_set_int(dist, 0x7fffffff, width * height);
  // initialize the distance from the source to the source to zero
  dist[source_y * width + source_x] = 0;


  int prev[width * height];
  // initialize the all node paths to "unknown"
  memory_set_int(prev, -1, width * height);

  // initialize the queue with "source"
  heap_append_xy(queue, &queue_length, 0, source_x, source_y);

  //while queue_length > 0:
}
