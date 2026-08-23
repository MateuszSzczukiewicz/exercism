#include "raindrops.h"
#include "stdio.h"
#include "string.h"

void convert(char result[], int drops) {
  result[0] = '\0';

  if (drops % 3 == 0) {
    strncat(result, "Pling", BUFFER_LENGTH - strlen(result) - 1);
  }

  if (drops % 5 == 0) {
    strncat(result, "Plang", BUFFER_LENGTH - strlen(result) - 1);
  }

  if (drops % 7 == 0) {
    strncat(result, "Plong", BUFFER_LENGTH - strlen(result) - 1);
  }

  if (result[0] == '\0') {
    snprintf(result, BUFFER_LENGTH, "%d", drops);
  }
}
