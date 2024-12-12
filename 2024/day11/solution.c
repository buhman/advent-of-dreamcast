#include <stdint.h>

#include "parse.h"
#include "unparse.h"
#include "printf.h"

static void split_base10(int64_t n, int digits, int64_t * a, int64_t * b)
{
  int pow = 1;
  digits /= 2;
  while (digits-- > 0)
    pow *= 10;
  int64_t split = pow;
  *a = n / split;
  *b = n % split;
}

static int stone_rule(int64_t n, int64_t * a, int64_t * b)
{
  int digits;
  if (n == 0) {
    *a = 1;
    return 1;
  } else if ((digits = digits_base10_64(n)) % 2 == 0) {
    split_base10(n, digits, a, b);
    return 2;
  } else {
    *a = n * 2024;
    return 1;
  }
}

struct entry {
  int64_t n;
  int32_t depth;
  int32_t _;
  int64_t value;
};

#define CACHE_LENGTH (262144)

struct cache {
  struct entry entry[CACHE_LENGTH];
  volatile int length;
};

static void sift_up(struct entry * e, int ix)
{
  while (ix > 0) {
    int parent = (ix - 1) / 2;
    if (e[parent].depth < e[ix].depth || e[parent].n < e[ix].n) {
      // swap parent and ix
      struct entry tmp = e[parent];
      e[parent] = e[ix];
      e[ix] = tmp;
      ix = parent;
    } else {
      return;
    }
  }
}

static int search(struct entry * e, int length, int ix, int64_t n, int32_t depth)
{
  if (e[ix].depth == depth && e[ix].n == n) {
    /*
    uint32_t r15;
    asm volatile ("mov r15,%0"
                  : "=r" (r15));
    if (r15 < min) {
      //printf("%08x\n", r15);
      min = r15;
    }
    */

    return ix;
  }

  int child_l = 2 * ix + 1;
  int child_r = 2 * ix + 2;

  if (child_r < length && (e[child_r].depth >= depth || e[child_r].n >= n)) {
    int i = search(e, length, child_r, n, depth);
    if (i >= 0)
      return i;
  }

  if (child_l < length && (e[child_l].depth >= depth || e[child_l].n >= n)) {
    int i = search(e, length, child_l, n, depth);
    if (i >= 0)
      return i;
  }

  return -1;
}

static void cache_add(struct cache * cache, int64_t n, int32_t depth, int64_t value)
{
  if (cache->length >= CACHE_LENGTH)
    return;

  int ix = cache->length;
  cache->entry[ix].n = n;
  cache->entry[ix].depth = depth;
  cache->entry[ix].value = value;
  sift_up(cache->entry, ix);
  cache->length += 1;
}

static int64_t simulate_step(int64_t n, int depth, int max_depth, struct cache * cache)
{
  if (depth == max_depth)
    return 1;

  int cache_ix = search(cache->entry, cache->length, 0, n, depth);
  if (cache_ix >= 0) {
    //printf("hit ix:%l %d %l\n", n, depth, cache->entry[cache_ix].value);
    return cache->entry[cache_ix].value;
  }

  int64_t a[2];
  int new_stones = stone_rule(n, &a[0], &a[1]);
  int64_t sum = 0;
  for (int i = 0; i < new_stones; i++) {
    sum += simulate_step(a[i], depth + 1, max_depth, cache);
  }

  //printf("store: %l %d %l\n", n, depth, sum);
  cache_add(cache, n, depth, sum);
  return sum;
}

static int parse_input(const char * input, int length,
                       int64_t * stones)
{
  const char * end = input + length;

  int i = 0;
  while (input < end) {
    input = parse_base10_64(input, &stones[i]);
    input = parse_skip(input, ' ');
    input = parse_skip(input, '\n');
    i += 1;
  }
  return i;
}

static int64_t solve(const char * input, int length, int max_depth)
{
  static struct cache cache;
  int64_t stones[20];

  int count = parse_input(input, length, stones);

  int64_t sum = 0;
  for (int i = 0; i < count; i++) {
    cache.length = 0;
    sum += simulate_step(stones[i], 0, max_depth, &cache);
  }

  return sum;
}

int64_t _2024_day11_part1(const char * input, int length)
{
  return solve(input, length, 25);
}

int64_t _2024_day11_part2(const char * input, int length)
{
  return solve(input, length, 75);
}
