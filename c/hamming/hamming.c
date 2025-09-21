#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
  int counter = 0;
  int lhs_len = 0;
  int rhs_len = 0;

  if (*lhs == '\0' && *rhs == '\0') {
    return 0;
  } else if (*lhs == '\0' || *rhs == '\0') {
    return -1;
  }

  for (int i = 0; lhs[i] != '\0' || rhs[i] != '\0'; i++) {
    if (lhs[i] != '\0') {
      lhs_len++;
    }

    if (rhs[i] != '\0') {
      rhs_len++;
    }

    if (lhs[i] != rhs[i]) {
      counter++;
    }
  }

  return lhs_len != rhs_len ? -1 : counter;
}
