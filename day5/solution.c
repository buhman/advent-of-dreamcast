#include <stdint.h>
#include <stdbool.h>

#include "parse.h"
#include "printf.h"

struct rule {
  char l;
  char r;
};

static void error(void)
{
  printf("day5: invalid input\n");
  while (1);
}

static const char * parse_rules(const char * input, const char * end,
                                struct rule * rules, int * rules_length)
{
  int i = 0;

  while (input < end) {
    int num;
    input = parse_base10(input, &num);
    if (*input++ != '|') { error(); }
    rules[i].l = num;

    input = parse_base10(input, &num);
    if (*input++ != '\n') { error(); }
    rules[i].r = num;

    i += 1;

    if (*input == '\n')
      break; // end of rules
  }

  *rules_length = i;

  return parse_skip(input, '\n');
}

static const char * parse_update(const char * input, const char * end,
                                 char * update, int * update_length)
{
  int i = 0;
  while (input < end) {
    int num;
    input = parse_base10(input, &num);
    input = parse_skip(input, ',');

    update[i] = num;
    i += 1;

    if (*input == '\n')
      break; // end of update
  }

  *update_length = i;

  return parse_skip(input, '\n');
}

static bool rule_match(const struct rule * rule, int a, int b)
{
  return rule->l == a && rule->r == b;
}

static bool sort_numbers(const struct rule * rules, int rules_length,
                         char * nums, int nums_length)
{
  bool at_least_one_swap = false;
  while (true) {
    bool swapped = false;
    for (int i = 0; i < nums_length - 1; i++) {
      int a = nums[i + 0];
      int b = nums[i + 1];

      for (int j = 0; j < rules_length; j++) {
        if (rule_match(&rules[j], b, a)) {
          swapped = true;
          at_least_one_swap = true;
          nums[i + 0] = b;
          nums[i + 1] = a;
        }
      }
    }
    if (!swapped)
      break;
  }

  return at_least_one_swap;
}

static int solve(const char * input, int length, bool correctly_ordered)
{
  const char * end = input + length;

  struct rule rules[1200];
  int rules_length;
  input = parse_rules(input, end, rules, &rules_length);

  int sum = 0;
  char update[24];
  while (input < end) {
    int update_length;
    input = parse_update(input, end, update, &update_length);

    bool at_least_one_swap = sort_numbers(rules, rules_length, update, update_length);
    if (correctly_ordered ^ at_least_one_swap) {
      sum += update[update_length / 2];
    }
  }

  return sum;
}

int64_t day5_part1(const char * input, int length)
{
  return solve(input, length, true);
}

int64_t day5_part2(const char * input, int length)
{
  return solve(input, length, false);
}
