#include <stdint.h>
#include <stdbool.h>

#include "parse.h"
#include "printf.h"
#include "unparse.h"

struct equation {
  int64_t value;
  int operand[32];
  int operand_count;
};

const char * parse_equation(const char * input, const char * end, struct equation * equation)
{
  input = parse_base10_64(input, &equation->value);
  input = parse_skip(input, ':');
  input = parse_skip(input, ' ');

  equation->operand_count = 0;
  while (*input != '\n') {
    input = parse_base10(input, &equation->operand[equation->operand_count++]);
    input = parse_skip(input, ' ');
  }

  return parse_skip(input, '\n');
}

static bool evaluate_equation1(struct equation * equation, int64_t acc, int depth)
{
  if (depth >= equation->operand_count)
    return acc == equation->value;

  int64_t operand = equation->operand[depth];

  int64_t acc1 = acc * operand;
  int64_t acc2 = acc + operand;
  return
       evaluate_equation1(equation, acc1, depth + 1)
    || evaluate_equation1(equation, acc2, depth + 1);
}

int64_t day7_part1(const char * input, int length)
{
  const char * end = input + length;

  int64_t sum = 0;
  while (input < end) {
    struct equation equation;
    input = parse_equation(input, end, &equation);

    bool possible = evaluate_equation1(&equation, equation.operand[0], 1);
    if (possible)
      sum += equation.value;
  }

  return sum;
}

static int64_t pow10[20] = {
  1ull,
  10ull,
  100ull,
  1000ull,
  10000ull,
  100000ull,
  1000000ull,
  10000000ull,
  100000000ull,
  1000000000ull,
  10000000000ull,
  100000000000ull,
  1000000000000ull,
  10000000000000ull,
  100000000000000ull,
  1000000000000000ull,
  10000000000000000ull,
  100000000000000000ull,
  1000000000000000000ull,
  10000000000000000000ull,
};

int64_t concatenate(int64_t a, int64_t b)
{
  int digits = digits_base10_64(b);
  a *= pow10[digits];
  return a + b;
}

static bool evaluate_equation2(struct equation * equation, int64_t acc, int depth)
{
  if (depth >= equation->operand_count)
    return acc == equation->value;

  int64_t operand = equation->operand[depth];

  int64_t acc1 = acc * operand;
  int64_t acc2 = acc + operand;
  int64_t acc3 = concatenate(acc, operand);
  return
       evaluate_equation2(equation, acc1, depth + 1)
    || evaluate_equation2(equation, acc2, depth + 1)
    || evaluate_equation2(equation, acc3, depth + 1);
}

int64_t day7_part2(const char * input, int length)
{
  const char * end = input + length;

  int64_t sum = 0;
  while (input < end) {
    struct equation equation;
    input = parse_equation(input, end, &equation);

    bool possible = evaluate_equation2(&equation, equation.operand[0], 1);
    if (possible)
      sum += equation.value;
  }

  return sum;
}
