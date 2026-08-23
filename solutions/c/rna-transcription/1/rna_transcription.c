#include "rna_transcription.h"
#include "stdlib.h"
#include "string.h"

char *to_rna(const char *dna) {
  char *rna = malloc((strlen(dna) + 1) * sizeof(char));
  char *rna_start = rna;

  while (*dna) {
    switch (*dna) {
    case 'G':
      *rna = 'C';
      break;
    case 'C':
      *rna = 'G';
      break;
    case 'T':
      *rna = 'A';
      break;
    case 'A':
      *rna = 'U';
      break;
    }

    rna++;
    dna++;
  }

  *rna = '\0';

  return rna_start;
}
