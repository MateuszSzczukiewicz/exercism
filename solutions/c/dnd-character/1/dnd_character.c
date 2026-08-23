#include "dnd_character.h"
#include "math.h"
#include "stdlib.h"

int ability(void) {
  int scores_array[4] = {0};
  int min = scores_array[0];
  int sum = 0;

  for (int i = 0; i < 4; i++) {
    scores_array[i] = rand() % (6 - 1 + 1) + 1;
    sum += scores_array[i];

    if (scores_array[i] < min) {
      min = scores_array[i];
    }
  }
  sum -= min;

  return sum;
}

int modifier(int score) { return floor((score - 10) / 2.0); }

dnd_character_t make_dnd_character(void) {
  dnd_character_t character;

  character.strength = ability();
  character.dexterity = ability();
  character.constitution = ability();
  character.intelligence = ability();
  character.wisdom = ability();
  character.charisma = ability();
  character.charisma = ability();
  character.hitpoints = 10 + modifier(character.constitution);

  return character;
}
