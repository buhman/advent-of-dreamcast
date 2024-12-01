all: $(patsubst %.cpp,%.elf,$(wildcard example/*.cpp))

include dreamcast/base.mk
include dreamcast/common.mk
include dreamcast/headers.mk

MAKEFILE_PATH := $(abspath $(firstword $(MAKEFILE_LIST)))
CFLAGS += -I$(dir $(MAKEFILE_PATH))
CFLAGS += -I$(dir $(MAKEFILE_PATH))dreamcast/
LIB ?= $(dir $(MAKEFILE_PATH))dreamcast

include aoc.mk
