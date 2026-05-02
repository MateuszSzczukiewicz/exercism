#include "high_scores.h"
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
  if (scores_len <= 0) {
    return 0;
  }

  return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
  if (scores_len <= 0) {
    return 0;
  }

  int32_t biggest_score = *scores;

  for (size_t i = 0; i < scores_len; ++i) {
    if (scores[i] > biggest_score) {
      biggest_score = scores[i];
    }
  }

  return biggest_score;
}

int32_t comp(const void *a, const void *b) {
  return (*(int32_t *)b - *(int32_t *)a);
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
  if (scores_len <= 0) {
    return 0;
  }

  int32_t scores_arr[scores_len];
  memcpy(scores_arr, scores, scores_len * sizeof *scores);
  qsort(scores_arr, scores_len, sizeof(int32_t), comp);

  size_t scores_arr_len = scores_len < 3 ? scores_len : 3;

  memcpy(output, scores_arr, scores_arr_len * sizeof(int32_t));

  return scores_arr_len;
}
