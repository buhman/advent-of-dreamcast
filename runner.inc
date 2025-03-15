int64_t _2023_day1_part1(const char * input, int length);
int64_t _2023_day1_part2(const char * input, int length);
int64_t _2023_day2_part1(const char * input, int length);
int64_t _2023_day2_part2(const char * input, int length);
int64_t _2023_day3_part1(const char * input, int length);
int64_t _2023_day3_part2(const char * input, int length);
int64_t _2023_day4_part1(const char * input, int length);
int64_t _2023_day4_part2(const char * input, int length);
int64_t _2024_day1_part1(const char * input, int length);
int64_t _2024_day1_part2(const char * input, int length);
int64_t _2024_day2_part1(const char * input, int length);
int64_t _2024_day2_part2(const char * input, int length);
int64_t _2024_day3_part1(const char * input, int length);
int64_t _2024_day3_part2(const char * input, int length);
int64_t _2024_day4_part1(const char * input, int length);
int64_t _2024_day4_part2(const char * input, int length);
int64_t _2024_day5_part1(const char * input, int length);
int64_t _2024_day5_part2(const char * input, int length);
int64_t _2024_day6_part1(const char * input, int length);
int64_t _2024_day6_part2(const char * input, int length);
void _2024_day6_render(const struct font * font,
                   const struct glyph * glyphs,
                   const void * maple_ft0_data);
int64_t _2024_day7_part1(const char * input, int length);
int64_t _2024_day7_part2(const char * input, int length);
int64_t _2024_day8_part1(const char * input, int length);
int64_t _2024_day8_part2(const char * input, int length);
int64_t _2024_day9_part1(const char * input, int length);
int64_t _2024_day9_part2(const char * input, int length);
int64_t _2023_day24_part1(const char * input, int length);
int64_t _2023_day24_part2(const char * input, int length);
int64_t _2024_day10_part1(const char * input, int length);
int64_t _2024_day10_part2(const char * input, int length);
int64_t _2024_day11_part1(const char * input, int length);
int64_t _2024_day11_part2(const char * input, int length);
int64_t _2024_day12_part1(const char * input, int length);
int64_t _2024_day12_part2(const char * input, int length);
int64_t _2024_day13_part1(const char * input, int length);
int64_t _2024_day13_part2(const char * input, int length);
int64_t _2024_day14_part1(const char * input, int length);
int64_t _2024_day14_part2(const char * input, int length);
void _2024_day14_render(const struct font * font,
                   const struct glyph * glyphs,
                   const void * maple_ft0_data);
int64_t _2024_day15_part1(const char * input, int length);
int64_t _2024_day15_part2(const char * input, int length);
int64_t _2024_day16_part1(const char * input, int length);
int64_t _2024_day16_part2(const char * input, int length);
int64_t _2024_day17_part1(const char * input, int length);
int64_t _2024_day17_part2(const char * input, int length);
int64_t _2024_day18_part1(const char * input, int length);
int64_t _2024_day18_part2(const char * input, int length);
int64_t _2024_day19_part1(const char * input, int length);
int64_t _2024_day19_part2(const char * input, int length);
int64_t _2024_day22_part1(const char * input, int length);
int64_t _2024_day22_part2(const char * input, int length);

struct day_funcs solution[] = {
  {
    2023, 1,
    {_2023_day1_part1, _2023_day1_part2},
    NULL,
  },
  {
    2023, 2,
    {_2023_day2_part1, _2023_day2_part2},
    NULL,
  },
  {
    2023, 3,
    {_2023_day3_part1, _2023_day3_part2},
    NULL,
  },
  {
    2023, 4,
    {_2023_day4_part1, _2023_day4_part2},
    NULL,
  },
  {
    2024, 1,
    {_2024_day1_part1, _2024_day1_part2},
    NULL,
  },
  {
    2024, 2,
    {_2024_day2_part1, _2024_day2_part2},
    NULL,
  },
  {
    2024, 3,
    {_2024_day3_part1, _2024_day3_part2},
    NULL,
  },
  {
    2024, 4,
    {_2024_day4_part1, _2024_day4_part2},
    NULL,
  },
  {
    2024, 5,
    {_2024_day5_part1, _2024_day5_part2},
    NULL,
  },
  {
    2024, 6,
    {_2024_day6_part1, _2024_day6_part2},
    _2024_day6_render,
  },
  {
    2024, 7,
    {_2024_day7_part1, _2024_day7_part2},
    NULL,
  },
  {
    2024, 8,
    {_2024_day8_part1, _2024_day8_part2},
    NULL,
  },
  {
    2024, 9,
    {_2024_day9_part1, _2024_day9_part2},
    NULL,
  },
  {
    2023, 24,
    {_2023_day24_part1, _2023_day24_part2},
    NULL,
  },
  {
    2024, 10,
    {_2024_day10_part1, _2024_day10_part2},
    NULL,
  },
  {
    2024, 11,
    {_2024_day11_part1, _2024_day11_part2},
    NULL,
  },
  {
    2024, 12,
    {_2024_day12_part1, _2024_day12_part2},
    NULL,
  },
  {
    2024, 13,
    {_2024_day13_part1, _2024_day13_part2},
    NULL,
  },
  {
    2024, 14,
    {_2024_day14_part1, _2024_day14_part2},
    _2024_day14_render,
  },
  {
    2024, 15,
    {_2024_day15_part1, _2024_day15_part2},
    NULL,
  },
  {
    2024, 16,
    {_2024_day16_part1, _2024_day16_part2},
    NULL,
  },
  {
    2024, 17,
    {_2024_day17_part1, _2024_day17_part2},
    NULL,
  },
  {
    2024, 18,
    {_2024_day18_part1, _2024_day18_part2},
    NULL,
  },
  {
    2024, 19,
    {_2024_day19_part1, _2024_day19_part2},
    NULL,
  },
  {
    2024, 22,
    {_2024_day22_part1, _2024_day22_part2},
    NULL,
  },
};
