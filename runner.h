#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct runner_state {
  int tick;
};

bool runner_tick(struct runner_state * runner_state);

#ifdef __cplusplus
}
#endif
