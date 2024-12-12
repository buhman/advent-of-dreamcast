#!/bin/bash

set -ex

year="$1"
day="$2"

if [ ! -z $year && ! -z "$year/$day" ]; then
    re='^[0-9]+$'
    if ! [[ $year =~ $re ]] ; then
        echo "error: $year: not a number" >&2
        exit 1
    fi
    if ! [[ $day =~ $re ]] ; then
        echo "error: $day: not a number" >&2
        exit 1
    fi

    mkdir -p ${year}/day${day}
    cat <<EOF > ${year}/day${day}/solution.c
#include <stdint.h>

int64_t ${year}_day${day}_part1(const char * input, int length)
{
  return -1;
}

int64_t ${year}_day${day}_part2(const char * input, int length)
{
  return -1;
}
EOF

    if [ ! -f ${year}/day${day}/sample1.txt ]; then
        touch ${year}/day${day}/sample1.txt
    fi

    if [ ! -f ${year}/day${day}/input.txt ]; then
        touch ${year}/day${day}/input.txt
    fi
fi

function binary_header_include ()
{
    echo "#include \"${1}/sample1.txt.h\"" >> input_dreamcast.inc
    if [ -f ${i}/sample2.txt ]; then
        echo "#include \"${1}/sample2.txt.h\"" >> input_dreamcast.inc
    fi
    echo "#include \"${1}/input.txt.h\"" >> input_dreamcast.inc
}

function gen_start_size ()
{
    local name=${2//\//_}
    echo "$1  { (  char *)&_binary_${name}_${3}_txt_start,"    >> input_dreamcast.inc
    echo "$1    (uint32_t)&_binary_${name}_${3}_txt_size   }," >> input_dreamcast.inc
}

function sample ()
{
    echo "  {"  >> input_dreamcast.inc
    gen_start_size "  " "${1}" "sample1"
    if [ ! -f ${i}/sample2.txt ]; then
        gen_start_size "  " "${1}" "sample1"
    else
        gen_start_size "  " "${1}" "sample2"
    fi
    echo "  }," >> input_dreamcast.inc
}

for i in ????/day? ????/day?? ; do
    make ${i}/sample1.txt.h ${i}/input.txt.h
    if [ -f ${i}/sample2.txt ]; then
        make ${i}/sample2.txt.h
    fi
done

truncate -s0 input_dreamcast.inc

for i in ????/day? ????/day?? ; do
    binary_header_include ${i}
done
echo >> input_dreamcast.inc
echo "static struct start_size sample[][2] = {" >> input_dreamcast.inc
for i in ????/day? ????/day?? ; do
    sample ${i}
done
echo "};" >> input_dreamcast.inc
echo >> input_dreamcast.inc
echo "static struct start_size input[] = {" >> input_dreamcast.inc
for i in ????/day? ????/day?? ; do
    gen_start_size "" "${i}" "input"
done
echo "};" >> input_dreamcast.inc

truncate -s0 solutions.mk
echo -n "DAY_OBJ =" >> solutions.mk
for i in ????/day? ????/day?? ; do
    echo " \\" >> solutions.mk
    echo "	${i}/sample1.txt.o \\" >> solutions.mk
    if [ -f ${i}/sample2.txt ]; then
        echo "	${i}/sample2.txt.o \\" >> solutions.mk
    fi
    echo "	${i}/input.txt.o \\" >> solutions.mk
    if [ -f ${i}/render.cpp ]; then
        echo "	${i}/render.o \\" >> solutions.mk
    fi
    echo -n "	${i}/solution.o" >> solutions.mk
done
echo >> solutions.mk

function part_declaration ()
{
    local name=${1//\//_}
    echo "int64_t _${name}_part1(const char * input, int length);" >> runner.inc
    echo "int64_t _${name}_part2(const char * input, int length);" >> runner.inc
    if [ -f ${1}/render.cpp ]; then
        echo "void _${name}_render(const struct font * font," >> runner.inc
        echo "                   const struct glyph * glyphs," >> runner.inc
        echo "                   const void * maple_ft0_data);" >> runner.inc
    fi
}

function solution_array_content ()
{
    local name=${1//\//_}
    regex='([0-9]+)/day([0-9]+)'
    [[ $1 =~ $regex ]]
    echo "  {" >> runner.inc
    echo "    ${BASH_REMATCH[1]}, ${BASH_REMATCH[2]}," >> runner.inc
    echo "    {_${name}_part1, _${name}_part2}," >> runner.inc
    if [ -f ${i}/render.cpp ]; then
        echo "    _${name}_render," >> runner.inc
    else
        echo "    NULL," >> runner.inc
    fi
    echo "  }," >> runner.inc
}

truncate -s0 runner.inc
for i in ????/day? ????/day?? ; do
    part_declaration ${i}
done
echo >> runner.inc
echo "struct day_funcs solution[] = {" >> runner.inc
for i in ????/day? ????/day?? ; do
    solution_array_content ${i}
done
echo "};" >> runner.inc
