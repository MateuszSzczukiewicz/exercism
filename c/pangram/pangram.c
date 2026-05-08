#include "pangram.h"
#include <ctype.h>
#include <stddef.h>

#define NUMBER_OF_LETTERS 26

bool is_pangram(const char *sentence) {
  if (sentence == NULL) {
    return false;
  }

  int seen[NUMBER_OF_LETTERS] = {0};

  for (size_t i = 0; sentence[i] != '\0'; ++i) {
    if (isalpha((unsigned char)sentence[i])) {
      int letter_index = tolower((unsigned char)sentence[i]) - 'a';

      seen[letter_index] = 1;
    }
  }

  for (size_t i = 0; i < NUMBER_OF_LETTERS; ++i) {
    if (seen[i] == 0) {
      return false;
    }
  }

  return true;
}
