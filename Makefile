all: $(patsubst %.cpp,%.elf,$(wildcard example/*.cpp))

OPT = -O0

MAKEFILE_PATH := $(patsubst %/,%,$(dir $(abspath $(firstword $(MAKEFILE_LIST)))))
CFLAGS += -I$(MAKEFILE_PATH)
CFLAGS += -I$(MAKEFILE_PATH)/dreamcast/
CFLAGS += -Wno-char-subscripts
LIB ?= $(MAKEFILE_PATH)/dreamcast

CARCH = -m4 -ml

include dreamcast/base.mk
include dreamcast/common.mk
include dreamcast/headers.mk

libgcc/%.o: $(LIBGCC)
	@mkdir -p $(dir $@)
	ar x --output $(dir $@) $(LIBGCC) $(notdir $@)
	sh4-none-elf-objdump -t $@ \
		| grep -E '[.]hidden' \
		| grep -vE 'UND' \
		| cut -d' ' -f10 \
		| xargs rebind --visibility=default $@

include aoc.mk
