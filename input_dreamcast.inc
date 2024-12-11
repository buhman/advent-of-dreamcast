#include "day1/sample1.txt.h"
#include "day1/input.txt.h"
#include "day2/sample1.txt.h"
#include "day2/input.txt.h"
#include "day3/sample1.txt.h"
#include "day3/sample2.txt.h"
#include "day3/input.txt.h"
#include "day4/sample1.txt.h"
#include "day4/input.txt.h"
#include "day5/sample1.txt.h"
#include "day5/input.txt.h"
#include "day6/sample1.txt.h"
#include "day6/input.txt.h"
#include "day7/sample1.txt.h"
#include "day7/input.txt.h"
#include "day8/sample1.txt.h"
#include "day8/input.txt.h"
#include "day9/sample1.txt.h"
#include "day9/input.txt.h"
#include "day10/sample1.txt.h"
#include "day10/input.txt.h"
#include "day11/sample1.txt.h"
#include "day11/input.txt.h"

static struct start_size sample[][2] = {
  {
    { (  char *)&_binary_day1_sample1_txt_start,
      (uint32_t)&_binary_day1_sample1_txt_size   },
    { (  char *)&_binary_day1_sample1_txt_start,
      (uint32_t)&_binary_day1_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_day2_sample1_txt_start,
      (uint32_t)&_binary_day2_sample1_txt_size   },
    { (  char *)&_binary_day2_sample1_txt_start,
      (uint32_t)&_binary_day2_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_day3_sample1_txt_start,
      (uint32_t)&_binary_day3_sample1_txt_size   },
    { (  char *)&_binary_day3_sample2_txt_start,
      (uint32_t)&_binary_day3_sample2_txt_size   },
  },
  {
    { (  char *)&_binary_day4_sample1_txt_start,
      (uint32_t)&_binary_day4_sample1_txt_size   },
    { (  char *)&_binary_day4_sample1_txt_start,
      (uint32_t)&_binary_day4_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_day5_sample1_txt_start,
      (uint32_t)&_binary_day5_sample1_txt_size   },
    { (  char *)&_binary_day5_sample1_txt_start,
      (uint32_t)&_binary_day5_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_day6_sample1_txt_start,
      (uint32_t)&_binary_day6_sample1_txt_size   },
    { (  char *)&_binary_day6_sample1_txt_start,
      (uint32_t)&_binary_day6_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_day7_sample1_txt_start,
      (uint32_t)&_binary_day7_sample1_txt_size   },
    { (  char *)&_binary_day7_sample1_txt_start,
      (uint32_t)&_binary_day7_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_day8_sample1_txt_start,
      (uint32_t)&_binary_day8_sample1_txt_size   },
    { (  char *)&_binary_day8_sample1_txt_start,
      (uint32_t)&_binary_day8_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_day9_sample1_txt_start,
      (uint32_t)&_binary_day9_sample1_txt_size   },
    { (  char *)&_binary_day9_sample1_txt_start,
      (uint32_t)&_binary_day9_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_day10_sample1_txt_start,
      (uint32_t)&_binary_day10_sample1_txt_size   },
    { (  char *)&_binary_day10_sample1_txt_start,
      (uint32_t)&_binary_day10_sample1_txt_size   },
  },
  {
    { (  char *)&_binary_day11_sample1_txt_start,
      (uint32_t)&_binary_day11_sample1_txt_size   },
    { (  char *)&_binary_day11_sample1_txt_start,
      (uint32_t)&_binary_day11_sample1_txt_size   },
  },
};

static struct start_size input[] = {
  { (  char *)&_binary_day1_input_txt_start,
    (uint32_t)&_binary_day1_input_txt_size   },
  { (  char *)&_binary_day2_input_txt_start,
    (uint32_t)&_binary_day2_input_txt_size   },
  { (  char *)&_binary_day3_input_txt_start,
    (uint32_t)&_binary_day3_input_txt_size   },
  { (  char *)&_binary_day4_input_txt_start,
    (uint32_t)&_binary_day4_input_txt_size   },
  { (  char *)&_binary_day5_input_txt_start,
    (uint32_t)&_binary_day5_input_txt_size   },
  { (  char *)&_binary_day6_input_txt_start,
    (uint32_t)&_binary_day6_input_txt_size   },
  { (  char *)&_binary_day7_input_txt_start,
    (uint32_t)&_binary_day7_input_txt_size   },
  { (  char *)&_binary_day8_input_txt_start,
    (uint32_t)&_binary_day8_input_txt_size   },
  { (  char *)&_binary_day9_input_txt_start,
    (uint32_t)&_binary_day9_input_txt_size   },
  { (  char *)&_binary_day10_input_txt_start,
    (uint32_t)&_binary_day10_input_txt_size   },
  { (  char *)&_binary_day11_input_txt_start,
    (uint32_t)&_binary_day11_input_txt_size   },
};
