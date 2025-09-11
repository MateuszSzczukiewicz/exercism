#include "grains.h"
#include <stdint.h>

uint64_t square(uint8_t index) {
  uint64_t prev = 1;

  for (uint8_t i = 1; i <= index; i++) {
    if (index == 1)
      return prev;

    prev *= 2;
  }

  return prev;
}

uint64_t total(void) { return square(64); }
