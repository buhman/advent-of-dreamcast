#!/bin/bash

set -ex

day="$1"

if [ ! -z "$day" ]; then
    re='^[0-9]+$'
    if ! [[ $day =~ $re ]] ; then
        echo "error: $day: not a number" >&2
        exit 1
    fi

    mkdir -p day${day}
    cat <<EOF > day${day}/solution.c
int day${day}_part1(const char * input, int length)
{
  return -1;
}

int day${day}_part2(const char * input, int length)
{
  return -1;
}
EOF

    if [ ! -f day${day}/sample1.txt ]; then
        touch day${day}/sample1.txt
    fi

    if [ ! -f day${day}/input.txt ]; then
        touch day${day}/input.txt
    fi
fi

function gen_start_size ()
{
    echo "$1  { (  char *)&_binary_${2}_${3}_txt_start,"    >> input_dreamcast.inc
    echo "$1    (uint32_t)&_binary_${2}_${3}_txt_size   }," >> input_dreamcast.inc
}


for i in day* ; do
    make ${i}/sample1.txt.h ${i}/input.txt.h
    if [ -f ${i}/sample2.txt ]; then
        make ${i}/sample2.txt.h
    fi
done


truncate -s0 input_dreamcast.inc

for i in day* ; do
    echo "#include \"${i}/sample1.txt.h\"" >> input_dreamcast.inc
    if [ -f ${i}/sample2.txt ]; then
        echo "#include \"${i}/sample2.txt.h\"" >> input_dreamcast.inc
    fi
    echo "#include \"${i}/input.txt.h\"" >> input_dreamcast.inc
done
echo >> input_dreamcast.inc
echo "static struct start_size sample[][2] = {" >> input_dreamcast.inc
for i in day* ; do
    echo "  {"  >> input_dreamcast.inc
    gen_start_size "  " "${i}" "sample1"
    if [ ! -f ${i}/sample2.txt ]; then
        gen_start_size "  " "${i}" "sample1"
    else
        gen_start_size "  " "${i}" "sample2"
    fi
    echo "  }," >> input_dreamcast.inc
done
echo "};" >> input_dreamcast.inc
echo >> input_dreamcast.inc
echo "static struct start_size input[] = {" >> input_dreamcast.inc
for i in day* ; do
    gen_start_size "" "${i}" "input"
done
echo "};" >> input_dreamcast.inc


truncate -s0 solutions.mk
echo -n "DAY_OBJ =" >> solutions.mk
for i in day* ; do
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

truncate -s0 runner.inc
for i in day* ; do
    echo "int ${i}_part1(const char * input, int length);" >> runner.inc
    echo "int ${i}_part2(const char * input, int length);" >> runner.inc
    if [ -f ${i}/render.cpp ]; then
        echo "void ${i}_render(const struct font * font," >> runner.inc
        echo "                 const struct glyph * glyphs," >> runner.inc
        echo "                 const void * maple_ft0_data);" >> runner.inc
    fi
done
echo >> runner.inc
echo "struct day_funcs solution[] = {" >> runner.inc
for i in day* ; do
    echo "  {" >> runner.inc
    echo "    {${i}_part1, ${i}_part2}," >> runner.inc
    if [ -f ${i}/render.cpp ]; then
        echo "    ${i}_render," >> runner.inc
    else
        echo "    NULL," >> runner.inc
    fi
    echo "  }," >> runner.inc
done
echo "};" >> runner.inc
