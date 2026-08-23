#include "binary.h"
#include "math.h"
#include <stdlib.h>
#include <string.h>

int convert(const char *input) {
  int output = 0;
  int length = strlen(input);

  while (*input) {
    if (!(*input == '0' || *input == '1')) {
      return INVALID;
    }

    output += (*input - '0') * pow(2, length - 1);

    length--;
    input++;
  }

  return output;
}
