#include "high_scores.h"
#include <stdint.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
  return scores[scores_len + 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
  int32_t biggest_score = *scores;

  for (int i = 0; i < scores_len; i++) {
    if (scores[i] > biggest_score) {
      biggest_score = scores[i];
    }
  }

  return biggest_score;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
  int32_t biggest_scores[3] = {0};

  for (int i = 0; i < 3; i++) {
    biggest_scores[i] = scores[i];
  }

  for (int i = 0; i < scores_len; i++) {
    if (scores[i] > biggest_scores) {
      biggest_scores = scores[i];
    }
  }

  return *biggest_scores;
}
