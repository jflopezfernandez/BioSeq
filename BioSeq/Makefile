
SHELL = /bin/sh

vpath %.c src
vpath %.h include

INCLUDES = -I include

CSTD = -std=c11
CHECK = -Wall -Wextra -pedantic
OPTIMIZATIONS = -O3 -mtune=intel -march=skylake -mavx2
ADDITIONAL_FLAGS = $(CSTD) $(CHECK) $(OPTIMIZATIONS)

PROGRAM = seq

all: $(PROGRAM)

$(PROGRAM): main.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(TARGET_ARCH) $(ADDITIONAL_FLAGS)    -o $@ $^ $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(TARGET_ARCH) $(ADDITIONAL_FLAGS) -c -o $@ $^

#analysis:
#

.PHONY: clean
clean:
	rm -rf *.o $(PROGRAM)
