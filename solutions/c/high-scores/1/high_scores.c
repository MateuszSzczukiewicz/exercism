#include "high_scores.h"
#include <stdint.h>

int32_t latest(const int32_t *scores, size_t scores_len)
{
  return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
  int32_t biggest_score = *scores;

  for (int i = 0; i < (int)scores_len; i++)
  {
    if (scores[i] > biggest_score)
    {
      biggest_score = scores[i];
    }
  }

  return biggest_score;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output)
{
  int32_t biggest_scores[3] = {0};

  for (int i = 0; i < (int)scores_len; i++)
  {
    if (i == 0)
    {
      biggest_scores[0] = scores[0];
    }
    else if (biggest_scores[i - 1] && scores[i] > biggest_scores[i - 1])
    {
      do
      {
        biggest_scores[i] = biggest_scores[i - 1];
        biggest_scores[i - 1] = scores[i];
      } while (i >= 2 && scores[i] > biggest_scores[i - 2]);
    }
  }

  *output = *biggest_scores;

  return scores_len;
}
