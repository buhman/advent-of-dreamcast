OBJ = \
	parse.o \
	heapsort.o \
	printf.o \
	runner.o \
	unparse.o \
	cartesian.o \
	array.o \
	memory.o

DREAMCAST_OBJ = \
	runner_dreamcast.o \
	input_dreamcast.o \
	sh7091_scif.o \
	$(LIB)/holly/core.o \
	$(LIB)/holly/region_array.o \
	$(LIB)/holly/background.o \
	$(LIB)/holly/ta_fifo_polygon_converter.o \
	$(LIB)/holly/video_output.o \
	$(LIB)/font/dejavusansmono/dejavusansmono.data.o \
	$(LIB)/sh7091/serial.o \
	$(LIB)/maple/maple.o \
	libgcc/_divdi3.o \
	libgcc/_moddi3.o \
	libgcc/_udiv_qrnnd_16.o \
	libgcc/_clz.o

include solutions.mk

aoc.elf: LDSCRIPT = $(LIB)/main.lds
aoc.elf: $(START_OBJ) $(OBJ) $(DREAMCAST_OBJ) $(DAY_OBJ)
