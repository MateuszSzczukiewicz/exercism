#include "raindrops.h"
#include "stdio.h"
#include "string.h"
#include <stdio.h>

void convert(char result[], int drops) {
  int position = 0;

  if (drops % 3 == 0) {
    position += snprintf(result + position, BUFFER_LENGTH - position, "Pling");
  }

  if (drops % 5 == 0) {
    position += snprintf(result + position, BUFFER_LENGTH - position, "Plang");
  }

  if (drops % 7 == 0) {
    position += snprintf(result + position, BUFFER_LENGTH - position, "Plong");
  }

  if (result[0] == '\0') {
    snprintf(result, BUFFER_LENGTH, "%d", drops);
  }
}
