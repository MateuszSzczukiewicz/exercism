#include "darts.h"

uint8_t score(coordinate_t position) {
  if (position.x < 0 || position.y < 0) {
    return 0;
  } else if (position.x <= 1 && position.y <= 1) {
    return 10;
  } else if (position.x <= 5 && position.y <= 5) {
    return 5;
  } else if (position.x <= 10 && position.y <= 10) {
    return 1;
  } else {
    return 0;
  }
}
