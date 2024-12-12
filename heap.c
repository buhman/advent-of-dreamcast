#include "heap.h"

void heap_sift_up(struct heap_entry * e, int ix)
{
  while (ix > 0) {
    int parent = (ix - 1) / 2;
    if (e[parent].key < e[ix].key) {
      // swap parent and ix
      struct heap_entry tmp = e[parent];
      e[parent] = e[ix];
      e[ix] = tmp;
      ix = parent;
    } else {
      return;
    }
  }
}

void heap_append(struct heap_entry * e, int * heap_length, int key, int value)
{
  int ix = *heap_length;
  e[ix].key = key;
  e[ix].value = value;
  heap_sift_up(e, ix);
  (*heap_length) += 1;
}

int heap_find(struct heap_entry * e, int length, int ix, int key)
{
  if (e[ix].key == key)
    return ix;

  int child_l = 2 * ix + 1;
  int child_r = 2 * ix + 2;

  if (child_r < length && e[child_r].key >= key) {
    int i = heap_find(e, length, child_r, key);
    if (i >= 0)
      return i;
  }

  if (child_l < length && e[child_l].key >= key) {
    int i = heap_find(e, length, child_l, key);
    if (i >= 0)
      return i;
  }

  return -1;
}
