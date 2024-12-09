#include <stdint.h>

#include "memory.h"
#include "printf.h"
#include "parse.h"

static int disk_map_to_blocks1(const char * input, int length,
                               int * blocks)
{
  int head = 0;
  int tail = (parse_find_first_right(input, length, '\n') - input) - 1;
  tail = (tail / 2) * 2; // round down to even index

  int ix = 0;

  int compact_file_id = -1;
  int compact_file_size = 0;

  while (head <= tail) {
    switch (head % 2) {
    case 0: // even : a file / id
      {
        int file_id = head / 2;
        int file_size = parse_base10_digit(input[head++]);
        while (file_size > 0) {
          blocks[ix++] = file_id;
          file_size -= 1;
        }
      }
      break;
    case 1: // odd  : free space
      {
        int free_space = parse_base10_digit(input[head++]);
        while (free_space > 0) {
          if (compact_file_size == 0) { // next from tail
            compact_file_id = tail / 2;
            compact_file_size = parse_base10_digit(input[tail]);
            tail -= 2;
          }
          blocks[ix++] = compact_file_id;
          compact_file_size -= 1;
          free_space -= 1;
        }
      }
      break;
    }
  }

  while (compact_file_size > 0) {
    blocks[ix++] = compact_file_id;
    compact_file_size -= 1;
  }

  return ix;
}

static int64_t calculate_checksum(int * blocks, int length)
{
  int64_t sum = 0;
  for (int i = 0; i < length; i++) {
    int64_t id = blocks[i];
    if (id < 0)
      continue;
    int64_t next_sum = sum + id * (int64_t)i;
    if (next_sum < sum)
      printf("overflow\n");
    sum = next_sum;
  }
  return sum;
}

static int allocate_leftmost_freespace(const char * free_list,
                                       int file_id,
                                       int file_size)
{
  for (int free_ix = 0; free_ix < file_id; free_ix += 1) {
    if (free_list[free_ix] >= file_size) {
      // allocate this free space to this file
      return free_ix;
    }
  }
  return -1;
}

static int disk_map_to_blocks2(const char * input, int length,
                               int * blocks)
{
  int tail = (parse_find_first_right(input, length, '\n') - input) - 1;
  tail = (tail / 2) * 2; // round down to even index

  char free_list[length / 2];
  for (int i = 0; i < length / 2; i++) {
    free_list[i] = parse_base10_digit(input[i * 2 + 1]);
  }

  int alloc_ids[length / 2];

  while (tail >= 0) {
    int file_id = tail / 2;
    int file_size = parse_base10_digit(input[tail]);

    int free_ix = allocate_leftmost_freespace(free_list,
                                              file_id,
                                              file_size);
    if (free_ix != -1) {
      // move the file to the free space
      free_list[free_ix] -= file_size;
      alloc_ids[file_id] = free_ix * 2 + 1;
    } else {
      // do not move the file
      alloc_ids[file_id] = file_id * 2 + 0;
    }

    tail -= 2;
  }

  /*
  for (int i = 0; i < length / 2; i++) {
    printf("%d %d ; ", i, alloc_ids[i]);
  }
  printf("\n");
  */

  // build the block list from alloc_ids
  int ix = 0;
  for (int disk_map_ix = 0; disk_map_ix < length; disk_map_ix++) {
    int map_size = parse_base10_digit(input[disk_map_ix]);

    // find alloc_ids for this disk_map_ix, starting from the end of alloc_ids
    for (int file_id = (length / 2) - 1; file_id >= 0; file_id -= 1) {
      if (alloc_ids[file_id] == disk_map_ix) {
        int file_size = parse_base10_digit(input[file_id * 2 + 0]);
        for (int i = 0; i < file_size; i++) {
          blocks[ix++] = file_id;
        }
        map_size -= file_size;
      }
    }

    // is there free space for this disk_map_ix?
    while (map_size > 0) {
      blocks[ix++] = -1;
      map_size -= 1;
    }
  }

  return ix;
}

static void print_blocks(int * blocks, int length)
{
  for (int i = 0; i < length; i++) {
    int file_id = blocks[i];
    if (file_id == -1)
      print_char('.');
    else
      printf("%d", file_id);
  }
  print_char('\n');
}

int64_t day9_part1(const char * input, int length)
{
  int blocks[length * 9];
  int ix = disk_map_to_blocks1(input, length, blocks);
  //print_blocks(blocks, ix);
  return calculate_checksum(blocks, ix);
}

int64_t day9_part2(const char * input, int length)
{
  int blocks[length * 9];
  int ix = disk_map_to_blocks2(input, length, blocks);
  //print_blocks(blocks, ix);
  return calculate_checksum(blocks, ix);
}
