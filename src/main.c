#include <time.h>
#include <stdio.h>
#include <stdint.h>

static uint64_t __rng_state;

void psrand(unsigned seed) { 
  __rng_state = seed;
}

int prand(void) {
  __rng_state = __rng_state*0x3243f6a8885a308d + 1;
  return __rng_state >> 32;
}

int plrand(int limit) {
  __rng_state = __rng_state*0x3243f6a8885a308d + 1;
  return ((__rng_state>>32) * limit) >> 32;
}

int main(int argc, char *argv[]) {
  psrand(time(NULL));

  for(;;) {
    // print random number between 0 - 100 (exclusive on highest boundary)
    printf("Random; %llu\n", plrand(101));
  }

  return 0;
}
