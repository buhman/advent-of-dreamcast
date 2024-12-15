#include <stdint.h>

#include "heap.h"
#include "parse.h"
#include "printf.h"
#include "memory.h"

static const char * parse_card(const char * input,
                               struct heap_entry * e,
                               int * heap_length,
                               int * numbers,
                               int * numbers_length
                               )
{
  input = parse_match(input, "Card");
  input = parse_skip(input, ' ');
  int card;
  input = parse_base10(input, &card);
  (void)card;
  input = parse_skip(input, ':');
  input = parse_skip(input, ' ');
  while (*input != '|') {
    int number;
    input = parse_base10(input, &number);
    input = parse_skip(input, ' ');

    heap_append(e, heap_length, number, 0);
  }

  input = parse_skip(input, '|');
  input = parse_skip(input, ' ');

  while (*input != '\n') {
    input = parse_base10(input, &numbers[(*numbers_length)++]);
    input = parse_skip(input, ' ');
  }
  input = parse_skip(input, '\n');

  return input;
}

int64_t _2023_day4_part1(const char * input, int length)
{
  const char * end = input + length;
  struct heap_entry e[20];
  int numbers[100];

  int sum = 0;

  while (input < end) {
    int heap_length = 0;
    int numbers_length = 0;

    input = parse_card(input, e, &heap_length, numbers, &numbers_length);
    int card_points = 0;

    for (int i = 0; i < numbers_length; i++) {
      int key = numbers[i];
      int ix = heap_find(e, heap_length, 0, key);
      if (ix >= 0) {
        if (card_points == 0)
          card_points = 1;
        else
          card_points *= 2;
      }
    }

    sum += card_points;
  }

  return sum;
}

int64_t _2023_day4_part2(const char * input, int length)
{
  const char * end = input + length;
  struct heap_entry e[20];
  int numbers[100];
  int height = parse_height(input, length);
  int card_duplicates[height];
  memory_set_int(card_duplicates, 1, height);

  int card_ix = 0;
  while (input < end) {
    int heap_length = 0;
    int numbers_length = 0;

    input = parse_card(input, e, &heap_length, numbers, &numbers_length);
    int card_points = 0;

    for (int i = 0; i < numbers_length; i++) {
      int key = numbers[i];
      int ix = heap_find(e, heap_length, 0, key);
      if (ix >= 0)
        card_points += 1;
    }

    for (int i = card_ix + 1; i < card_ix + 1 + card_points; i++) {
      card_duplicates[i] += card_duplicates[card_ix];
    }

    card_ix += 1;
  }

  int sum = 0;
  for (int i = 0; i < height; i++) {
    sum += card_duplicates[i];
  }

  return sum;
}
