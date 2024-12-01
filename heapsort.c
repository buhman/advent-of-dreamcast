#include "heapsort.h"

static inline void swap(int * a, int * b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

static inline int left_child_index(int i)
{
  return 2 * i + 1;
}

void heapsort(int * l, int length)
{
  int start = length / 2;
  int end = length;
  while (end > 1) {
    if (start > 0) {
      start = start - 1;
    } else {
      end = end - 1;
      swap(&l[end], &l[0]);
    }

    int root = start;
    while (left_child_index(root) < end) {
      int child = left_child_index(root);
      int right_child = child + 1;
      if (right_child < end && l[child] < l[right_child]) {
        child = right_child;
      }
      if (l[root] < l[child]) {
        swap(&l[root], &l[child]);
        root = child;
      } else {
        break;
      }
    }
  }
}

#ifdef HEAPSORT_TEST
#include <stdio.h>

int main()
{
  int l[] = {3, 5, 1, 8, 2, 8, 7, 5, 4, 9};
  int l_length = (sizeof (l)) / (sizeof (l[0]));
  heapsort(l, l_length);

  for (int i = 0; i < l_length; i++) {
    printf("%d ", l[i]);
  }
  printf("\n");
}
#endif
