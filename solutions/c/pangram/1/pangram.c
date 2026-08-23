#include "pangram.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_LETTERS 26

int comp(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

bool is_pangram(const char *sentence) {
  if (sentence == NULL) {
    return false;
  }

  int seen[NUMBER_OF_LETTERS];

  memset(seen, 0, sizeof(seen));

  for (size_t i = 0; sentence[i] != '\0'; ++i) {
    if (isalpha(sentence[i])) {
      int letter_index = tolower((unsigned char)sentence[i]) - 'a';

      seen[letter_index] = 1;
    }
  }

  for (int i = 0; i < NUMBER_OF_LETTERS; ++i) {
    if (seen[i] == 0) {
      return false;
    }
  }

  return true;
}
