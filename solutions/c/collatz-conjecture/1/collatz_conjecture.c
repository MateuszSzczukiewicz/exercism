#include "collatz_conjecture.h"

int steps(int start) {
  int counter = 0;
  int current = start;

  if (start < 2)
    return 0;

  while (current != 1) {
    if (current % 2 == 0) {
      current = current / 2;
    } else {
      current = (current / 3) + 1;
    }
    current++;
  }

  return counter;
}
