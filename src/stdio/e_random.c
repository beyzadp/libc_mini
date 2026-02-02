#include <e_lib.h>

static unsigned int _rand_seed = 1;

void e_srand(unsigned int seed) { _rand_seed = seed; }

unsigned int e_random(void) {
    _rand_seed = _rand_seed * 1103515245 + 12345;
    return (_rand_seed / 65536) % 32768;
}