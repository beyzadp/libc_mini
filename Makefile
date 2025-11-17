INCLUDES = -Iinclude
SRC := $(wildcard src/stdio/*.c) $(wildcard src/syscalls/*.c)
SERVERSRC := $(wildcard servers/*.c)
TESTS := $(wildcard tests/*.c)
EXECS := $(patsubst tests/%.c,build/%,${TESTS}) $(patsubst servers/%.c,build/%,${SERVERSRC})
CFLAGS = -O0 -g3 -ggdb

# Build rules for each executable
build/%: tests/%.c $(SRC)
	@mkdir -p build
	@gcc $(INCLUDES) $(SRC) $(CFLAGS) $< -o $@

build/%: servers/%.c $(SRC)
	@mkdir -p build
	@gcc $(INCLUDES) $(SRC) $(CFLAGS) $< -o $@

all: $(EXECS)

clean:
	rm -f build/*