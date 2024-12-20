#include <stdint.h>

#include "printf.h"
#include "parse.h"

struct state {
  int pc;
  int64_t a;
  int64_t b;
  int64_t c;
  char mem[256];
  int mem_length;
  char out[256];
  int out_length;
};

static int64_t combo_operand(struct state * state, int operand)
{
  switch (operand) {
  case 0: return 0;
  case 1: return 1;
  case 2: return 2;
  case 3: return 3;
  case 4: return state->a;
  case 5: return state->b;
  case 6: return state->c;
  default:
    printf("invalid combo operand %d\n", operand);
    return -1;
  }
}

static bool op_adv(struct state * state, int operand)
{
  int64_t value = combo_operand(state, operand);
  const int64_t one = 1;
  state->a = state->a / (one << value);
  return true;
}

static bool op_bxl(struct state * state, int operand)
{
  state->b = state->b ^ (int64_t)operand;
  return true;
}

static bool op_bst(struct state * state, int operand)
{
  int64_t value = combo_operand(state, operand);
  state->b = value % 8;
  return true;
}

static bool op_jnz(struct state * state, int operand)
{
  if (state->a != 0) {
    state->pc = operand;
    return false;
  } else {
    return true;
  }
}

static bool op_bxc(struct state * state, int operand)
{
  state->b = state->b ^ state->c;
  return true;
}

static bool op_out(struct state * state, int operand)
{
  int64_t value = combo_operand(state, operand);
  state->out[state->out_length++] = value % 8;
  return true;
}

static bool op_bdv(struct state * state, int operand)
{
  int64_t value = combo_operand(state, operand);
  state->b = state->a / (1 << value);
  return true;
}

static bool op_cdv(struct state * state, int operand)
{
  int64_t value = combo_operand(state, operand);
  state->c = state->a / (1 << value);
  return true;
}

static const char * parse_register(const char * input, char c, int * value)
{
  input = parse_match(input, "Register ");
  input = parse_skip(input, c);
  input = parse_match(input, ": ");
  input = parse_base10(input, value);
  input = parse_skip(input, '\n');
  return input;
}

static void step(struct state * state)
{
  int op = state->mem[state->pc];
  int operand = state->mem[state->pc+1];
  bool incpc;
  switch (op) {
  case 0: incpc = op_adv(state, operand); break;
  case 1: incpc = op_bxl(state, operand); break;
  case 2: incpc = op_bst(state, operand); break;
  case 3: incpc = op_jnz(state, operand); break;
  case 4: incpc = op_bxc(state, operand); break;
  case 5: incpc = op_out(state, operand); break;
  case 6: incpc = op_bdv(state, operand); break;
  case 7: incpc = op_cdv(state, operand); break;
  default:
    printf("invalid opcode %d\n", op);
    return;
  }
  if (incpc)
    state->pc = state->pc + 2;
}

static const char * parse_program(const char * input, const char * end, struct state * state)
{
  input = parse_match(input, "Program: ");

  int value;
  state->mem_length = 0;
  input = parse_base10(input, &value);
  state->mem[state->mem_length++] = value;
  while (input < end) {
    input = parse_skip(input, ',');
    input = parse_base10(input, &value);
    state->mem[state->mem_length++] = value;
    input = parse_skip(input, '\n');
  }
  return input;
}

static inline void run_until_halt(struct state * state)
{
  while (state->pc < state->mem_length) {
    step(state);
  }
}

static void parse_input(const char * input, int length, struct state * state)
{
  const char * end = input + length;

  state->pc = 0;
  state->out_length = 0;

  int reg;
  input = parse_register(input, 'A', &reg);
  state->a = reg;
  input = parse_register(input, 'B', &reg);
  state->b = reg;
  input = parse_register(input, 'C', &reg);
  state->c = reg;

  input = parse_skip(input, '\n');
  parse_program(input, end, state);
}

static void print_out(struct state * state)
{
  printf("%d", state->out[0]);
  for (int i = 1; i < state->out_length; i++) {
    printf(",%d", state->out[i]);
  }
  print_char('\n');
}

int64_t _2024_day17_part1(const char * input, int length)
{
  struct state state;
  parse_input(input, length, &state);

  run_until_halt(&state);
  print_out(&state);

  return -1;
}

static inline bool out_eq_mem(const struct state * state)
{
  if (state->mem_length != state->out_length) {
    return false;
  }

  for (int i = 0; i < state->mem_length; i++) {
    if (state->mem[i] != state->out[i]) {
      return false;
    }
  }
  return true;
}

int64_t _2024_day17_part2(const char * input, int length)
{
  struct state state;
  parse_input(input, length, &state);

  int64_t a = 1;
  int64_t last_a = a;
  while (true) {
    state.a = a;
    state.b = 0;
    state.c = 0;
    state.pc = 0;
    state.out_length = 0;

    run_until_halt(&state);

    if (state.out_length < state.mem_length) {
      last_a = a;
      a *= 2;
    } else {
      break;
    }
  }

  a = last_a;
  while (true) {
    state.a = a;
    state.b = 0;
    state.c = 0;
    state.pc = 0;
    state.out_length = 0;

    run_until_halt(&state);

    if (out_eq_mem(&state))
      break;

    a += 1;
  }

  print_out(&state);

  return a;
}
