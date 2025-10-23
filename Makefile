INCLUDES = -Iinclude
SRC := $(wildcard src/stdio/*.c) $(wildcard src/syscalls/*.c)
TESTS := $(wildcard tests/*.c)
EXECS := $(patsubst tests/%.c,build/%,${TESTS})
CFLAGS = -O0 -g3 -ggdb

# Build rules for each executable
build/%: tests/%.c $(SRC)
	@mkdir -p build
	@gcc $(INCLUDES) $(SRC) $(CFLAGS) $< -o $@

all: $(EXECS)

clean:
	rm -f build/*