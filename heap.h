#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct heap_entry {
  int key;
  int value;
};

void heap_sift_up(struct heap_entry * e, int ix);
void heap_append(struct heap_entry * e, int * heap_length, int key, int value);
int heap_find(struct heap_entry * e, int length, int ix, int key);

#ifdef __cplusplus
}
#endif
