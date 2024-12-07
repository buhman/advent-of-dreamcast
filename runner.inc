int day1_part1(const char * input, int length);
int day1_part2(const char * input, int length);
int day2_part1(const char * input, int length);
int day2_part2(const char * input, int length);
int day3_part1(const char * input, int length);
int day3_part2(const char * input, int length);
int day4_part1(const char * input, int length);
int day4_part2(const char * input, int length);
int day5_part1(const char * input, int length);
int day5_part2(const char * input, int length);
int day6_part1(const char * input, int length);
int day6_part2(const char * input, int length);
void day6_render(const struct font * font,
                 const struct glyph * glyphs,
                 const void * maple_ft0_data);

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
};
