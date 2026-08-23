#include "grains.h"
#include <stdint.h>

uint64_t square(uint8_t index) {
  if (index == 1)
    return 1;

  uint64_t prev = 1;
  for (uint8_t i = 1; i <= index; i++) {
    prev *= 2;
    if (i == index)
      return prev;
  }

  return prev;
}

uint64_t total(void) { return square(64); }
