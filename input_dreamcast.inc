#include "2023/day1/sample1.txt.h"
#include "2023/day1/sample2.txt.h"
#include "2023/day1/input.txt.h"
#include "2023/day2/sample1.txt.h"
#include "2023/day2/input.txt.h"
#include "2023/day3/sample1.txt.h"
#include "2023/day3/input.txt.h"
#include "2024/day1/sample1.txt.h"
#include "2024/day1/input.txt.h"
#include "2024/day2/sample1.txt.h"
#include "2024/day2/input.txt.h"
#include "2024/day3/sample1.txt.h"
#include "2024/day3/sample2.txt.h"
#include "2024/day3/input.txt.h"
#include "2024/day4/sample1.txt.h"
#include "2024/day4/input.txt.h"
#include "2024/day5/sample1.txt.h"
#include "2024/day5/input.txt.h"
#include "2024/day6/sample1.txt.h"
#include "2024/day6/input.txt.h"
#include "2024/day7/sample1.txt.h"
#include "2024/day7/input.txt.h"
#include "2024/day8/sample1.txt.h"
#include "2024/day8/input.txt.h"
#include "2024/day9/sample1.txt.h"
#include "2024/day9/input.txt.h"
#include "2024/day10/sample1.txt.h"
#include "2024/day10/input.txt.h"
#include "2024/day11/sample1.txt.h"
#include "2024/day11/input.txt.h"
#include "2024/day12/sample1.txt.h"
#include "2024/day12/sample2.txt.h"
#include "2024/day12/input.txt.h"

static struct start_size sample[][2] = {
  {
    { (  char *)&_binary_2023_day1_sample1_txt_start,
      (uint32_t)&_binary_2023_day1_sample1_txt_size   },
    { (  char *)&_binary_2023_day1_sample2_txt_start,
      (uint32_t)&_binary_2023_day1_sample2_txt_size   },
  },
  {
    { (  char *)&_binary_2023_day2_sample1_txt_start,
      (uint32_t)&_binary_2023_day2_sample1_txt_size   },
    { (  char *)&_binary_2023_day2_sample1_txt_start,
      (uint32_t)&_binary_2023_day2_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2023_day3_sample1_txt_start,
      (uint32_t)&_binary_2023_day3_sample1_txt_size   },
    { (  char *)&_binary_2023_day3_sample1_txt_start,
      (uint32_t)&_binary_2023_day3_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day1_sample1_txt_start,
      (uint32_t)&_binary_2024_day1_sample1_txt_size   },
    { (  char *)&_binary_2024_day1_sample1_txt_start,
      (uint32_t)&_binary_2024_day1_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day2_sample1_txt_start,
      (uint32_t)&_binary_2024_day2_sample1_txt_size   },
    { (  char *)&_binary_2024_day2_sample1_txt_start,
      (uint32_t)&_binary_2024_day2_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day3_sample1_txt_start,
      (uint32_t)&_binary_2024_day3_sample1_txt_size   },
    { (  char *)&_binary_2024_day3_sample2_txt_start,
      (uint32_t)&_binary_2024_day3_sample2_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day4_sample1_txt_start,
      (uint32_t)&_binary_2024_day4_sample1_txt_size   },
    { (  char *)&_binary_2024_day4_sample1_txt_start,
      (uint32_t)&_binary_2024_day4_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day5_sample1_txt_start,
      (uint32_t)&_binary_2024_day5_sample1_txt_size   },
    { (  char *)&_binary_2024_day5_sample1_txt_start,
      (uint32_t)&_binary_2024_day5_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day6_sample1_txt_start,
      (uint32_t)&_binary_2024_day6_sample1_txt_size   },
    { (  char *)&_binary_2024_day6_sample1_txt_start,
      (uint32_t)&_binary_2024_day6_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day7_sample1_txt_start,
      (uint32_t)&_binary_2024_day7_sample1_txt_size   },
    { (  char *)&_binary_2024_day7_sample1_txt_start,
      (uint32_t)&_binary_2024_day7_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day8_sample1_txt_start,
      (uint32_t)&_binary_2024_day8_sample1_txt_size   },
    { (  char *)&_binary_2024_day8_sample1_txt_start,
      (uint32_t)&_binary_2024_day8_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day9_sample1_txt_start,
      (uint32_t)&_binary_2024_day9_sample1_txt_size   },
    { (  char *)&_binary_2024_day9_sample1_txt_start,
      (uint32_t)&_binary_2024_day9_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day10_sample1_txt_start,
      (uint32_t)&_binary_2024_day10_sample1_txt_size   },
    { (  char *)&_binary_2024_day10_sample1_txt_start,
      (uint32_t)&_binary_2024_day10_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day11_sample1_txt_start,
      (uint32_t)&_binary_2024_day11_sample1_txt_size   },
    { (  char *)&_binary_2024_day11_sample1_txt_start,
      (uint32_t)&_binary_2024_day11_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_2024_day12_sample1_txt_start,
      (uint32_t)&_binary_2024_day12_sample1_txt_size   },
    { (  char *)&_binary_2024_day12_sample2_txt_start,
      (uint32_t)&_binary_2024_day12_sample2_txt_size   },
  },
};

static struct start_size input[] = {
  { (  char *)&_binary_2023_day1_input_txt_start,
    (uint32_t)&_binary_2023_day1_input_txt_size   },
  { (  char *)&_binary_2023_day2_input_txt_start,
    (uint32_t)&_binary_2023_day2_input_txt_size   },
  { (  char *)&_binary_2023_day3_input_txt_start,
    (uint32_t)&_binary_2023_day3_input_txt_size   },
  { (  char *)&_binary_2024_day1_input_txt_start,
    (uint32_t)&_binary_2024_day1_input_txt_size   },
  { (  char *)&_binary_2024_day2_input_txt_start,
    (uint32_t)&_binary_2024_day2_input_txt_size   },
  { (  char *)&_binary_2024_day3_input_txt_start,
    (uint32_t)&_binary_2024_day3_input_txt_size   },
  { (  char *)&_binary_2024_day4_input_txt_start,
    (uint32_t)&_binary_2024_day4_input_txt_size   },
  { (  char *)&_binary_2024_day5_input_txt_start,
    (uint32_t)&_binary_2024_day5_input_txt_size   },
  { (  char *)&_binary_2024_day6_input_txt_start,
    (uint32_t)&_binary_2024_day6_input_txt_size   },
  { (  char *)&_binary_2024_day7_input_txt_start,
    (uint32_t)&_binary_2024_day7_input_txt_size   },
  { (  char *)&_binary_2024_day8_input_txt_start,
    (uint32_t)&_binary_2024_day8_input_txt_size   },
  { (  char *)&_binary_2024_day9_input_txt_start,
    (uint32_t)&_binary_2024_day9_input_txt_size   },
  { (  char *)&_binary_2024_day10_input_txt_start,
    (uint32_t)&_binary_2024_day10_input_txt_size   },
  { (  char *)&_binary_2024_day11_input_txt_start,
    (uint32_t)&_binary_2024_day11_input_txt_size   },
  { (  char *)&_binary_2024_day12_input_txt_start,
    (uint32_t)&_binary_2024_day12_input_txt_size   },
};
