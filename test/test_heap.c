#include <stdio.h>
#include <stdint.h>

#include "runner.h"

#include "heap.h"

static bool heap_test_0(const char ** scenario)
{
  *scenario = "heap_extract_max";



  return false;
}

test_t heap_tests[] = {
  heap_test_0,
};

RUNNER(heap_tests)
