#include "resistor_color_trio.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

resistor_value_t color_code(resistor_band_t *colors_trio) {
  double value = pow(10.0, (double)colors_trio[2]);
  resistor_unit_t unit;

  char buffer[3];
  sprintf(buffer, "%d%d", colors_trio[0], colors_trio[1]);
  int num = atoi(buffer);
  value *= num;

  if (value >= 1000000000) {
    value /= 1000000000;
    unit = GIGAOHMS;
  } else if (value >= 1000000) {
    value /= 1000000;
    unit = MEGAOHMS;
  } else if (value >= 1000) {
    value /= 1000;
    unit = KILOOHMS;
  } else {
    unit = OHMS;
  }

  resistor_value_t code;
  code.value = value;
  code.unit = unit;

  return code;
}
