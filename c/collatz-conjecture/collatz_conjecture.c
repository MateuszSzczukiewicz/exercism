#include "collatz_conjecture.h"

int steps(int start) {
  int counter = 0;
  int current = start;

  if (start <= 0)
    return ERROR_VALUE;

  if (start == 1)
    return 0;

  while (current != 1) {
    if (current % 2 == 0) {
      current = current / 2;
    } else {
      current = (current * 3) + 1;
    }
    counter++;
  }

  return counter;
}
