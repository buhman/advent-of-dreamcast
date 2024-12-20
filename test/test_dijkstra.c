#include <stdio.h>
#include <stdint.h>

#include "runner.h"

#include "dijkstra.h"
#include "memory.h"

static const char * graph =
"###############\n"
"#.......#....E#\n"
"#.#.###.#.###.#\n"
"#.....#.#...#.#\n"
"#.###.#####.#.#\n"
"#.#.#.......#.#\n"
"#.#.#####.###.#\n"
"#...........#.#\n"
"###.#.#####.#.#\n"
"#...#.....#.#.#\n"
"#.#.#.###.#.#.#\n"
"#.....#...#.#.#\n"
"#.###.#.#.#.#.#\n"
"#S..#.....#...#\n"
"###############\n"
  ;

static bool dijkstra_test_0(const char ** scenario)
{
  *scenario = "dijkstra";

  int width = 15;
  int height = 15;
  int stride = 16;
  int start_x = 1;
  int start_y = 13;
  int end_x = 13;
  int end_y = 1;

  struct dijkstra_xy16 prev[width * height];
  int dist[width * height];

  int turn_cost = 100;
  dijkstra_cartesian(graph,
                     stride,
                     width, height,
                     end_x, end_y,
                     start_x, start_y,
                     '#',
                     turn_cost,
                     prev,
                     dist);

  char map[stride * height];
  memory_copy_char(graph, stride * height, map);

  int x = end_x;
  int y = end_y;
  int cost = 0;
  while (!(x == start_x && y == start_y)) {
    printf("%2d %2d %d\n", x, y, dist[y * width + x]);
    struct dijkstra_xy16 xy = prev[y * width + x];
    map[xy.y * stride + xy.x] = 'x';
    x = xy.x;
    y = xy.y;
  }
  printf("%2d %2d %d\n", x, y, dist[y * width + x]);

  printf("%d\n", cost);
  puts(map);

  return true;
}

test_t dijkstra_tests[] = {
  dijkstra_test_0,
};

RUNNER(dijkstra_tests)
