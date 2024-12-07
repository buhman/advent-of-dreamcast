#include <stdbool.h>
#include <stddef.h>

#include "parse.h"
#include "printf.h"

struct mul
{
  int x;
  int y;
};

enum instruction_type {
  INSTRUCTION_MUL,
  INSTRUCTION_DO,
  INSTRUCTION_DONT,
};

struct instruction {
  enum instruction_type type;
  struct mul mul;
};

const char * parse_instruction(const char * input, const char * end, struct instruction * ins)
{
  while (input < end) {
    const char * mdo = parse_match(input, "do()");
    if (mdo != NULL) {
      ins->type = INSTRUCTION_DO;
      return mdo;
    }
    const char * mdont = parse_match(input, "don't()");
    if (mdont != NULL) {
      ins->type = INSTRUCTION_DONT;
      return mdont;
    }

    const char * m = parse_match(input, "mul(");
    if (m == NULL) {
      input++;
      continue;
    }
    input = m;

    const char * x = parse_base10(input, &ins->mul.x);
    if (x == input) continue;
    input = x;
    if (ins->mul.x < 0 || ins->mul.x > 999) continue;

    const char * c = parse_match(input, ",");
    if (c == NULL) continue;
    input = c;

    const char * y = parse_base10(input, &ins->mul.y);
    if (y == input) continue;
    input = y;
    if (ins->mul.y < 0 || ins->mul.y > 999) continue;

    const char * p = parse_match(input, ")");
    if (p == NULL) continue;
    input = p;

    ins->type = INSTRUCTION_MUL;

    return input;
  }

  return NULL;
}

int parse_input(const char * input, int length, struct instruction * ins)
{
  const char * end = input + length;

  int i = 0;
  while (true) {
    if (i >= 1000) {
      printf("error: ins limit exceeded\n");
      return 0;
    }

    input = parse_instruction(input, end, &ins[i]);
    if (input == NULL)
      break;
    i += 1;
  }

  return i;
}

int day3_part1(const char * input, int length)
{
  struct instruction ins[1000];

  int mul_length = parse_input(input, length, ins);

  int sum = 0;
  for (int i = 0; i < mul_length; i++) {
    if (ins[i].type == INSTRUCTION_MUL)
      sum += ins[i].mul.x * ins[i].mul.y;
  }

  return sum;
}

int day3_part2(const char * input, int length)
{
  struct instruction ins[1000];

  int mul_length = parse_input(input, length, ins);

  int mul_enabled = true;
  int sum = 0;
  for (int i = 0; i < mul_length; i++) {
    switch (ins[i].type) {
    case INSTRUCTION_MUL:
      if (mul_enabled)
        sum += ins[i].mul.x * ins[i].mul.y;
      break;
    case INSTRUCTION_DO:
      mul_enabled = true;
      break;
    case INSTRUCTION_DONT:
      mul_enabled = false;
      break;
    }
  }

  return sum;
}
