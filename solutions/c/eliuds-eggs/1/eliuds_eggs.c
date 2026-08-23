#include "eliuds_eggs.h"
#include "stdlib.h"

unsigned int egg_count(unsigned int count) {
  unsigned int eggs_quantity = 0;
  unsigned int divisor = 1;

  while (divisor < count) {
    divisor *= 2;
  }

  while (count > 0) {
    if (divisor <= count) {
      count -= divisor;
      eggs_quantity += 1;
    }

    divisor /= 2;
  }

  return eggs_quantity;
}
