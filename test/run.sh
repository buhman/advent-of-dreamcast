#!bin/bash

set -eux

for i in test/test_heap.c; do
    name=${i%.c}
    gcc -Og -g -gdwarf-5 \
        -std=c2x \
        -Wall -Werror -Wfatal-errors \
        -Wno-error=unused-variable \
        -I. \
        -o ${name} \
        ${name}.c \
        memory.c \
        dijkstra.c \
        heap.c \
        cartesian.c

    ./${name}
done
