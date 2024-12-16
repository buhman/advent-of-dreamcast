#include <stdio.h>
#include <stdint.h>

#include "runner.h"

#include "heap.h"

static bool heap_test_0(const char ** scenario)
{
  *scenario = "heap_extract_max";

  struct heap_entry e[100];
  int heap_length = 0;
  int n[] = {-17, -57, -84, -88, -44, -77, -13, -80, -51, -37, -54, -74, -51, -74, -69, -15, -53, -74, -48, -93, -18, -14, -97, -35, -72, -73, -85, -42, -9, -53, -47, -93, -63, -81, -41, -48, -52, -67, -58, -24, -70, -4, -9, -67, -29, -54, -26, -35, -23, -96, -83, -68, -88, -73, -70, -71, -41, -78, -91, -96, -6, -33, -15, -56, -95, -62, -62, -88, -37, -96, -86, -53, -82, -84, -73, -25, -94, -1, -9, -80, -99, -35, -81, -51, -19, -64, -6, -88, -94, -30, -3, -88, -63, -43, -40, -86, -48, -66, -16, -21};
  for (int i = 0; i < 100; i++) {
    heap_append(e, &heap_length, n[i], 0);
  }

  int max = 999;
  while (heap_length > 0) {
    struct heap_entry ei = heap_extract_max(e, &heap_length);
    printf("%d %d\n", ei.key, max);
    if (ei.key > max)
      return false;
    max = ei.key;
  }

  return true;
}

test_t heap_tests[] = {
  heap_test_0,
};

RUNNER(heap_tests)
