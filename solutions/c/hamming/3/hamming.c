#include "hamming.h"
#include <stdio.h>
#include <string.h>

int compute(const char *lhs, const char *rhs) {
  int counter = 0;

  if (*lhs == '\0' && *rhs == '\0') {
    return 0;
  } else if (*lhs == '\0' || *rhs == '\0') {
    return -1;
  } else if (strlen(lhs) != strlen(rhs)) {
    return -1;
  }

  for (int i = 0; lhs[i] != '\0' && rhs[i] != '\0'; i++) {
    if (lhs[i] != rhs[i]) {
      counter++;
    }
  }

  return counter;
}
