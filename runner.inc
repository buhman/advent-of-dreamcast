int day1_part1(char * input, int length);
int day1_part2(char * input, int length);
int day2_part1(char * input, int length);
int day2_part2(char * input, int length);
int day3_part1(char * input, int length);
int day3_part2(char * input, int length);
int day4_part1(char * input, int length);
int day4_part2(char * input, int length);

part_func solution[][2] = {
  {day1_part1, day1_part2},
  {day2_part1, day2_part2},
  {day3_part1, day3_part2},
  {day4_part1, day4_part2},
};
