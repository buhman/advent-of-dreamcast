#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct heap_entry {
  int key;
  union {
    int value;
    struct {
      int16_t x;
      int16_t y;
    };
  };
};

void heap_sift_up(struct heap_entry * e, int ix);
void heap_sift_down(struct heap_entry * e, int heap_length, int ix);
void heap_append(struct heap_entry * e, int * heap_length, int key, int value);
void heap_append_xy(struct heap_entry * e, int * heap_length, int key, int x, int y);
int heap_find(struct heap_entry * e, int length, int ix, int key);
struct heap_entry heap_extract_max(struct heap_entry * e, int * heap_length);

#ifdef __cplusplus
}
#endif
