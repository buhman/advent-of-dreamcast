#include <stdint.h>

#include "memory.h"

void memory_set_char(char * buf, char c, int length)
{
  for (int i = 0; i < length; i += 1) {
    buf[i] = c;
  }
}

void memory_set_int(int * buf, int c, int length)
{
  for (int i = 0; i < length; i += 1) {
    buf[i] = c;
  }
}
