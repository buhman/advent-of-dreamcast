#include <stdbool.h>
#include <stddef.h>

#include "parse.h"

int parse_base10_digit(char c)
{
  switch (c) {
  case '0': return 0;
  case '1': return 1;
  case '2': return 2;
  case '3': return 3;
  case '4': return 4;
  case '5': return 5;
  case '6': return 6;
  case '7': return 7;
  case '8': return 8;
  case '9': return 9;
  default: return -1;
  }
}

const char * parse_skip(const char * s, char c)
{
  while (*s == c) {
    s++;
  }
  return s;
}

const char * parse_find(const char * s, char c)
{
  while (*s != c) {
    s++;
  }
  return s;
}

const char * parse_find_first_right(const char * s, int length, char c)
{
  const char * ss = &s[length - 1];
  while (ss >= s) {
    if (*ss == c)
      return ss;
    ss--;
  }
  return s;
}

const char * parse_base10(const char * s, int * n)
{
  *n = 0;
  int sign = 1;

  if (*s == '-') {
    sign = -1;
    s++;
  }

  while (true) {
    int digit = parse_base10_digit(*s);
    if (digit == -1)
      break;

    *n *= 10;
    *n += digit;
    s++;
  }

  *n *= sign;

  return s;
}

const char * parse_base10_64(const char * s, int64_t * n)
{
  *n = 0;
  int sign = 1;

  if (*s == '-') {
    sign = -1;
    s++;
  }

  while (true) {
    int digit = parse_base10_digit(*s);
    if (digit == -1)
      break;

    *n *= 10;
    *n += digit;
    s++;
  }

  *n *= sign;

  return s;
}

const char * parse_match(const char * s, const char * m)
{
  while (*m != 0) {
    if (*s++ != *m++) {
      return NULL;
    }
  }
  return s;
}

int parse_stride(const char * s, int length)
{
  for (int i = 0; i < length; i++) {
    if (s[i] == '\n') {
      return i + 1;
    }
  }
  return -1;
}

int parse_height(const char * s, int length)
{
  int rows = 0;
  int i;
  for (i = 0; i < length; i++) {
    if (s[i] == '\n') {
      rows += 1;
    }
  }
  if (s[i-1] != '\n') {
    rows += 1;
  }
  return rows;
}
