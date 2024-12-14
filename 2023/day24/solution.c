#include <stdint.h>

#include "parse.h"
#include "printf.h"

#include "double.h"

struct vec3 {
  double x;
  double y;
  double z;
};

typedef struct vec3 vec3;

static bool line_line_intersection_2d(vec3 * a, vec3 * da,
                                      vec3 * b, vec3 * db,
                                      vec3 * intersection)
{
  double a1, b1, c1, a2, b2, c2;
  if (da->x == 0) {
    a1 = 0;
    b1 = 1;
    c1 = a->x;
  } else {
    a1 = -da->y;
    b1 = da->x;
    c1 = b1 * a->y + a1 * a->x;
  }
  if (db->x == 0) {
    a2 = 0;
    b2 = 1;
    c2 = b->x;
  } else {
    a2 = -db->y;
    b2 = db->x;
    c2 = b2 * b->y + a2 * b->x;
  }

  double denom = (a1 * b2) - (a2 * b1);
  if (denom == 0)
    return false;

  double x = ((c1 * b2) - (c2 * b1)) / denom;
  double y = ((a1 * c2) - (a2 * c1)) / denom;

  intersection->x = x;
  intersection->y = y;

  return true;
}

static const char * parse_line(const char * input, vec3 * p, vec3 * v)
{
  int64_t x, y, z;
  int64_t dx, dy, dz;
  input = parse_base10_64(input, &x);
  input = parse_skip(input, ',');
  input = parse_skip(input, ' ');
  input = parse_base10_64(input, &y);
  input = parse_skip(input, ',');
  input = parse_skip(input, ' ');
  input = parse_base10_64(input, &z);
  input = parse_skip(input, ' ');
  input = parse_skip(input, '@');
  input = parse_skip(input, ' ');
  input = parse_base10_64(input, &dx);
  input = parse_skip(input, ',');
  input = parse_skip(input, ' ');
  input = parse_base10_64(input, &dy);
  input = parse_skip(input, ',');
  input = parse_skip(input, ' ');
  input = parse_base10_64(input, &dz);
  input = parse_skip(input, ',');
  input = parse_skip(input, ' ');
  input = parse_skip(input, '\n');

  p->x = (double)(x);
  p->y = (double)(y);
  p->z = (double)(z);
  v->x = (double)(dx);
  v->y = (double)(dy);
  v->z = (double)(dz);

  return input;
}

static bool in_bounds(vec3 * a,
                      double min,
                      double max)
{
  return
    a->x >= min && a->x <= max &&
    a->y >= min && a->y <= max;
}

struct position_velocity {
  vec3 position;
  vec3 velocity;
};

int64_t _2023_day24_part1(const char * input, int length)
{
  const char * end = input + length;

  struct position_velocity hailstone[301];
  int hailstone_length = 0;

  while (input < end) {
    struct position_velocity * pv = &hailstone[hailstone_length++];
    const char * i = parse_line(input, &pv->position, &pv->velocity);
    input = i;
  }

  int sum = 0;

  for (int i = 0; i < hailstone_length; i++) {
    for (int j = i + 1; j < hailstone_length; j++) {
      struct vec3 intersection;
      struct position_velocity * hi = &hailstone[i];
      struct position_velocity * hj = &hailstone[j];

      bool intersect = line_line_intersection_2d(&hi->position,
                                                 &hi->velocity,
                                                 &hj->position,
                                                 &hj->velocity,
                                                 &intersection);
      if (!intersect)
        continue;

      if ((intersection.x - hi->position.x) * hi->velocity.x < 0 ) {
        continue;
      }
      if ((intersection.x - hj->position.x) * hj->velocity.x < 0 ) {
        continue;
      }

      if (in_bounds(&intersection,
                    200000000000000.0,
                    400000000000000.0)) {
        sum += 1;
      }
    }
  }

  return sum;
}

int64_t _2023_day24_part2(const char * input, int length)
{
  return -1;
}
