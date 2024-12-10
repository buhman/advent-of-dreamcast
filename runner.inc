int64_t day1_part1(const char * input, int length);
int64_t day1_part2(const char * input, int length);
int64_t day2_part1(const char * input, int length);
int64_t day2_part2(const char * input, int length);
int64_t day3_part1(const char * input, int length);
int64_t day3_part2(const char * input, int length);
int64_t day4_part1(const char * input, int length);
int64_t day4_part2(const char * input, int length);
int64_t day5_part1(const char * input, int length);
int64_t day5_part2(const char * input, int length);
int64_t day6_part1(const char * input, int length);
int64_t day6_part2(const char * input, int length);
void day6_render(const struct font * font,
                 const struct glyph * glyphs,
                 const void * maple_ft0_data);
int64_t day7_part1(const char * input, int length);
int64_t day7_part2(const char * input, int length);
int64_t day8_part1(const char * input, int length);
int64_t day8_part2(const char * input, int length);
int64_t day9_part1(const char * input, int length);
int64_t day9_part2(const char * input, int length);
int64_t day10_part1(const char * input, int length);
int64_t day10_part2(const char * input, int length);

struct day_funcs solution[] = {
  {
    {day1_part1, day1_part2},
    NULL,
  },
  {
    {day2_part1, day2_part2},
    NULL,
  },
  {
    {day3_part1, day3_part2},
    NULL,
  },
  {
    {day4_part1, day4_part2},
    NULL,
  },
  {
    {day5_part1, day5_part2},
    NULL,
  },
  {
    {day6_part1, day6_part2},
    day6_render,
  },
  {
    {day7_part1, day7_part2},
    NULL,
  },
  {
    {day8_part1, day8_part2},
    NULL,
  },
  {
    {day9_part1, day9_part2},
    NULL,
  },
  {
    {day10_part1, day10_part2},
    NULL,
  },
};
