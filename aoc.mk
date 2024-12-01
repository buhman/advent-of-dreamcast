OBJ = \
	parse.o \
	heapsort.o \
	printf.o \
	runner.o \
	unparse.o

DREAMCAST_OBJ = \
	runner_dreamcast.o \
	input_dreamcast.o \
	$(LIB)/holly/core.o \
	$(LIB)/holly/region_array.o \
	$(LIB)/holly/background.o \
	$(LIB)/holly/ta_fifo_polygon_converter.o \
	$(LIB)/holly/video_output.o \
	$(LIB)/font/dejavusansmono/dejavusansmono.data.o \
	$(LIB)/sh7091/serial.o

DAY1_OBJ = \
	day1/sample1.txt.o \
	day1/input.txt.o \
	day1/solution.o

aoc.elf: LDSCRIPT = $(LIB)/main.lds
aoc.elf: $(START_OBJ) $(OBJ) $(DREAMCAST_OBJ) $(DAY1_OBJ)
