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

void memory_copy_char(const char * src, int length, char * dst)
{
  for (int i = 0; i < length; i += 1) {
    dst[i] = src[i];
  }
}

void memory_copy_u32(const void * _src, int length, void * _dst)
{
  // size given in bytes
  const uint32_t * src = _src;
  uint32_t * dst = _dst;

  for (int i = 0; i < length; i++) {
    dst[i] = src[i];
  }
}
