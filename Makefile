all: $(patsubst %.cpp,%.elf,$(wildcard example/*.cpp))

OPT = -Og

include dreamcast/base.mk
include dreamcast/common.mk
include dreamcast/headers.mk

MAKEFILE_PATH := $(patsubst %/,%,$(dir $(abspath $(firstword $(MAKEFILE_LIST)))))
CFLAGS += -I$(MAKEFILE_PATH)
CFLAGS += -I$(MAKEFILE_PATH)/dreamcast/
CFLAGS += -Wno-char-subscripts
LIB ?= $(MAKEFILE_PATH)/dreamcast

include aoc.mk
