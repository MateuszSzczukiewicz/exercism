#include "perfect_numbers.h"

kind classify_number(int number) {
  int sum = 0;

  for (int i = 1; i < number; i++) {
    if (number % i == 0) {
      sum += i;
    }
  }

  if (number < 1) {
    return ERROR;
  } else if (sum == number) {
    return PERFECT_NUMBER;
  } else if (sum < number) {
    return DEFICIENT_NUMBER;
  } else if (sum > number) {
    return ABUNDANT_NUMBER;
  }

  return ERROR;
}
