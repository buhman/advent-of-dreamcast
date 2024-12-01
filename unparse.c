#include <stdint.h>
#include <stdbool.h>

#include "minmax.h"

static int digits_base10(uint32_t n)
{
  if (n >= 1000000000) return 10;
  if (n >= 100000000) return 9;
  if (n >= 10000000) return 8;
  if (n >= 1000000) return 7;
  if (n >= 100000) return 6;
  if (n >= 10000) return 5;
  if (n >= 1000) return 4;
  if (n >= 100) return 3;
  if (n >= 10) return 2;
  return 1;
}

int unparse_base10(char * s, int32_t n, int len, char fill)
{
  bool negative = false;
  int digits = 0;
  if (n < 0) {
    digits += 1;
    n = -n;
    negative = true;
  }

  digits += digits_base10(n);
  len = max(digits, len);
  int ret = len;

  while (len > digits) {
    *s++ = fill;
    --len;
  }

  if (negative) {
    *s++ = '-';
    len--;
  }

  while (len > 0) {
    const uint32_t digit = n % 10;
    n = n / 10;
    s[--len] = digit + 48;
  }

  return ret;
}

static int digits_base16(uint32_t n)
{
  if (n <= 0xf) return 1;
  if (n <= 0xff) return 2;
  if (n <= 0xfff) return 3;
  if (n <= 0xffff) return 4;
  if (n <= 0xfffff) return 5;
  if (n <= 0xffffff) return 6;
  if (n <= 0xfffffff) return 7;
  return 8;
}

int unparse_base16(char * s, uint32_t n, int len, char fill)
{
  int digits = digits_base16(n);
  len = max(digits, len);
  int ret = len;

  while (len > digits) {
    *s++ = fill;
    --len;
  }

  while (len > 0) {
    uint32_t nib = n & 0xf;
    n = n >> 4;
    if (nib > 9) {
      nib += (97 - 10);
    } else {
      nib += (48 - 0);
    }

    s[--len] = nib;
  }

  return ret;
}

#ifdef UNPARSE_TEST
#include <stdio.h>

int main()
{
  char s[1024];

  {
    int n = 124;

    int offset = unparse_base10(s, n, 6, ' ');
    s[offset] = 0;

    printf("`%s`\n", s);
  }

  {
    int n = 0x5678;

    int offset = unparse_base16(s, n, 7, '0');
    s[offset] = 0;

    printf("`%s`\n", s);
  }
}
#endif
