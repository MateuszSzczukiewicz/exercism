#include "resistor_color_duo.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint16_t color_code(resistor_band_t colors_duo[1]) {
  char buffer[256];
  sprintf(buffer, "%d%d", colors_duo[0], colors_duo[1]);
  return atoi(buffer);
}
