INCLUDES = -Iinclude
SRC := $(wildcard src/stdio/*.c)
TESTS := $(wildcard tests/*.c)

# For each test, create a corresponding exec name (basename under build/)
EXECS := $(patsubst tests/%.c,build/%,${TESTS})

# Build rules for each executable
build/%: tests/%.c $(SRC)
	@mkdir -p build
	@gcc $(INCLUDES) $(SRC) $< -o $@

all: $(EXECS)

clean:
	rm -f build/*