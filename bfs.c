#include <stdint.h>

#include "memory.h"
#include "cartesian.h"
#include "bfs.h"

struct queue_descriptor {
  int start;
  int end;
};

struct position {
  int16_t x;
  int16_t y;
};

static inline void queue_append(struct position * queue,
                                struct queue_descriptor * qd,
                                int x,
                                int y)
{
  queue[qd->end].x = x;
  queue[qd->end].y = y;
  qd->end += 1;
}

static inline struct position * queue_pop(struct position * queue,
                                          struct queue_descriptor * qd)
{
  struct position * position = &queue[qd->start];
  qd->start += 1;
  return position;
}

void bfs(const char * graph,
         int stride,
         int width, int height,
         int start_x, int start_y,
         char wall,
         struct cartesian_link * path)
{
  struct position queue[width * height];
  struct queue_descriptor qd;
  qd.start = 0;
  qd.end = 0;

  memory_set_int((int *)path, -1, width * height);
  path[start_y * width + start_x].parent_x = start_x;
  path[start_y * width + start_x].parent_y = start_y;

  queue_append(&queue, &qd, start_x, start_y);

  while (qd.start != qd.end) {
    struct position * p = queue_pop(&queue, &qd);

    for (int i = 0; i < 4; i++) {
      int nx = p->x + cartesian_neighbor[i].x;
      int ny = p->y + cartesian_neighbor[i].y;
      // ignore all edges that are outside the graph
      if (!cartesian_inside(width, height, nx, ny))
        continue;
      // ignore all edges that are walls
      if (graph[ny * stride + nx] == wall)
        continue;
      // ignore all edges that were previously visited
      if (path[ny * width + nx].parent_x != -1)
        continue;

      path[ny * width + nx].parent_x = p->x;
      path[ny * width + nx].parent_y = p->y;

      queue_append(&queue, &qd, nx, ny);
    }
  }
}
