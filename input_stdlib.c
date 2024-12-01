#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"

static void read_file(const char * filename, char ** buf, int * length)
{
  FILE * f = fopen(filename, "rb");
  assert(f != NULL);
  int ret = fseek(f, 0L, SEEK_END);
  assert(ret >= 0);
  long size = ftell(f);
  assert(size > 0);
  rewind(f);

  *buf = malloc(size);

  size_t read = fread(*buf, 1, size, f);
  assert(read == size);

  *length = size;
}

void open_input(int day, char ** buf, int * length)
{
  char filename[1024];

  const char * format = "day%d/input.txt";
  snprintf(filename, (sizeof (filename)), format, day);

  read_file(filename, buf, length);
}

void open_sample(int day, int part, char ** buf, int * length)
{
  char filename[1024];

  const char * format = "day%d/sample%d.txt";
  snprintf(filename, (sizeof (filename)), format, day, part);

  read_file(filename, buf, length);
}
