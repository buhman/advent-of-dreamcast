#include <stdio.h>
#include <stdint.h>

#include "runner.h"

#include "memory.h"

static bool memory_test_0(const char ** scenario)
{
  *scenario = "memory_copy_u32 ordering";

  uint32_t l[] = {1, 2, 3, 4};

  memory_copy_u32(&l[1], 3, &l[0]);

  return l[0] == 2 && l[1] == 3 && l[2] == 4;
}

test_t memory_tests[] = {
  memory_test_0,
};

RUNNER(memory_tests)
