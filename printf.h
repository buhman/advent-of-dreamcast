#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void _printf(const char * format, ...);

#ifndef PRINTF_TEST
#define printf(...) _printf(__VA_ARGS__)
#endif

struct output_buffer {
  int buf_ix;
  char buf[16 * 1024];
};

extern struct output_buffer global_output_buffer;

#ifdef __cplusplus
}
#endif
