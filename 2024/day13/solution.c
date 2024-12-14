#include <stdint.h>

#include "linear_algebra.h"
#include "parse.h"

struct button {
  int x;
  int y;
};

struct prize {
  int x;
  int y;
};

struct claw_machine {
  struct {
    struct button a;
    struct button b;
  } button;
  struct prize prize;
};

static const char * parse_button(const char * input, char c,
                                 int * x, int * y)
{
  input = parse_match(input, "Button ");
  input = parse_skip(input, c);
  input = parse_match(input, ": X+");
  input = parse_base10(input, x);
  input = parse_match(input, ", Y+");
  input = parse_base10(input, y);
  input = parse_skip(input, '\n');
  return input;
}

static const char * parse_prize(const char * input,
                                int * x, int * y)
{
  input = parse_match(input, "Prize: X=");
  input = parse_base10(input, x);
  input = parse_match(input, ", Y=");
  input = parse_base10(input, y);
  input = parse_skip(input, '\n');
  return input;
}

static const char * parse_claw_machine(const char * input,
                                       struct claw_machine * cm)
{
  input = parse_button(input, 'A', &cm->button.a.x, &cm->button.a.y);
  input = parse_button(input, 'B', &cm->button.b.x, &cm->button.b.y);
  input = parse_prize(input, &cm->prize.x, &cm->prize.y);
  return input;
}

static bool is_integral(double x)
{
  int64_t ix = x;
  double dx = ix;
  double diff = dx - x;
  return (diff < 0.00000001) && (diff > -0.00000001);
}

int64_t _2024_day13_part1(const char * input, int length)
{
  const char * end = input + length;

  int cost = 0;

  while (input < end) {
    struct claw_machine cm;
    input = parse_claw_machine(input, &cm);

    double ax = cm.button.a.x;
    double ay = cm.button.a.y;
    double bx = cm.button.b.x;
    double by = cm.button.b.y;
    double x = cm.prize.x;
    double y = cm.prize.y;

    struct double2 r = cramers_rule_2x2(ax, bx, x,
                                        ay, by, y);
    if (is_integral(r.x) && is_integral(r.y)) {
      int a = (int)r.x;
      int b = (int)r.y;
      cost += a * 3 + b;
    }
  }
  return cost;
}

int64_t _2024_day13_part2(const char * input, int length)
{
  const char * end = input + length;

  int64_t cost = 0;

  while (input < end) {
    struct claw_machine cm;
    input = parse_claw_machine(input, &cm);

    double ax = cm.button.a.x;
    double ay = cm.button.a.y;
    double bx = cm.button.b.x;
    double by = cm.button.b.y;
    double x = cm.prize.x;
    double y = cm.prize.y;
    x += 10000000000000;
    y += 10000000000000;

    struct double2 r = cramers_rule_2x2(ax, bx, x,
                                        ay, by, y);
    if (r.x == infinity || r.y == infinity) {
      continue;
    }
    if (is_integral(r.x) && is_integral(r.y)) {
      int64_t a = (int64_t)(r.x);
      int64_t b = (int64_t)(r.y);
      cost += a * 3 + b;
    }
  }
  return cost;
}
