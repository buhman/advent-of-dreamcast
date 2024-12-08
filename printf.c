#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#include "parse.h"
#include "unparse.h"
#include "printf.h"

enum format_type {
  FORMAT_BASE10,
  FORMAT_BASE10_64,
  FORMAT_BASE16,
  FORMAT_STRING,
  FORMAT_CHAR,
  FORMAT_PERCENT,
};

struct format {
  enum format_type type;
  int pad_length;
  char fill_char;
};

static const char * parse_escape(const char * format, struct format * ft);

static const char * parse_fill_pad(const char * format, struct format * ft)
{
  if (*format == 0)
    return format;
  ft->fill_char = *format++;
  format = parse_base10(format, &ft->pad_length);
  return parse_escape(format, ft);
}

static const char * parse_escape(const char * format, struct format * ft)
{
  switch (*format) {
  case 0:
    return format;
  case 'd':
    ft->type = FORMAT_BASE10;
    return format + 1;
  case 'l':
    ft->type = FORMAT_BASE10_64;
    return format + 1;
  case 'x':
    ft->type = FORMAT_BASE16;
    return format + 1;
  case 's':
    ft->type = FORMAT_STRING;
    return format + 1;
  case 'c':
    ft->type = FORMAT_CHAR;
    return format + 1;
  case '%':
    ft->type = FORMAT_PERCENT;
    return format + 1;
  default:
    return parse_fill_pad(format, ft);
  }
}

struct output_buffer global_output_buffer = {0};

void _printf(const char * format, ...)
{
  va_list args;
  va_start(args, format);

  while (true) {
    if (*format == 0)
      break;

    switch (*format) {
    case '%':
      {
        struct format ft = {0};
        format = parse_escape(format + 1, &ft);
        switch (ft.type) {
        case FORMAT_BASE10:
          {
            int32_t num = va_arg(args, int32_t);
            char * s = &global_output_buffer.buf[global_output_buffer.buf_ix];
            int offset = unparse_base10(s, num, ft.pad_length, ft.fill_char);
            global_output_buffer.buf_ix += offset;
          }
          break;
        case FORMAT_BASE10_64:
          {
            int64_t num = va_arg(args, int64_t);
            char * s = &global_output_buffer.buf[global_output_buffer.buf_ix];
            int offset = unparse_base10_64(s, num, ft.pad_length, ft.fill_char);
            global_output_buffer.buf_ix += offset;
          }
          break;
        case FORMAT_BASE16:
          {
            uint32_t num = va_arg(args, uint32_t);
            char * s = &global_output_buffer.buf[global_output_buffer.buf_ix];
            int offset = unparse_base16(s, num, ft.pad_length, ft.fill_char);
            global_output_buffer.buf_ix += offset;
          }
          break;
        case FORMAT_STRING:
          {
            const char * s = va_arg(args, const char *);
            while (*s != 0) {
              global_output_buffer.buf[global_output_buffer.buf_ix++] = *s++;
            }
          }
          break;
        case FORMAT_CHAR:
          {
            const int c = va_arg(args, const int);
            global_output_buffer.buf[global_output_buffer.buf_ix++] = (char)c;
          }
          break;
        case FORMAT_PERCENT:
          global_output_buffer.buf[global_output_buffer.buf_ix++] = '%';
          break;
        }
      }
      break;
    default:
      global_output_buffer.buf[global_output_buffer.buf_ix++] = *format++;
      break;
    }
  }

  va_end(args);
}

#ifdef PRINTF_TEST
#include <stdio.h>

int main()
{
  _printf("test `% 8d` %s foobar\n", 1234, "hello");
  _printf("test2 `% 8d` %s foobar\n", -1234, "bar");

  global_output_buffer.buf[global_output_buffer.buf_ix] = 0;

  puts(global_output_buffer.buf);
}
#endif
