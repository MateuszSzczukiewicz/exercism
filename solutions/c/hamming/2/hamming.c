#include "hamming.h"

int compute(const char *lhs, const char *rhs) {

  int counter = 0;

  for (int i = 0; lhs[i] != '\0' && rhs[i] != '\0'; i++) {
    if ((lhs[i] == '\0' && rhs[i] != '\0') ||
        (rhs[i] == '\0' && lhs[i] != '\0')) {
      return -1;
    }

    if (lhs[i] != rhs[i]) {
      counter++;
    }
  }

  return counter;
}
