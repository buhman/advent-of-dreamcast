#include "heap.h"
#include "memory.h"

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

void heap_sift_down(struct heap_entry * e, int heap_length, int ix)
{
  while (true) {
    int child_l = 2 * ix + 1;
    int child_r = 2 * ix + 2;
    if (child_l >= heap_length)
      break;

    int child = child_l;
    if (child_r < heap_length && e[child_l].key < e[child_r].key) {
      child = child_r;
    }

    if (e[ix].key < e[child].key) {
      // swap child and ix
      struct heap_entry tmp = e[child];
      e[child] = e[ix];
      e[ix] = tmp;
      ix = child;
    } else {
      break;
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

void heap_append_xy(struct heap_entry * e, int * heap_length, int key, int x, int y)
{
  int ix = *heap_length;
  e[ix].key = key;
  e[ix].x = x;
  e[ix].y = y;
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

#define u32_per_heap_entry ((sizeof (struct heap_entry)) / (sizeof (uint32_t)))

struct heap_entry heap_extract_max(struct heap_entry * e, int * heap_length)
{
  struct heap_entry entry = e[0];
  (*heap_length)--;
  e[0] = e[*heap_length];
  heap_sift_down(e, *heap_length, 0);

  return entry;
}
