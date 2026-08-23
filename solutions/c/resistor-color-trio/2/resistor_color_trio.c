#include "resistor_color_trio.h"
#include <stdint.h>
#include <stdlib.h>

resistor_value_t color_code(resistor_band_t *colors_trio) {
  int64_t multiplier = 1;

  for (size_t i = 0; i < colors_trio[2]; ++i) {
    multiplier *= 10;
  }

  int64_t value = (colors_trio[0] * 10 + colors_trio[1]) * multiplier;
  resistor_unit_t unit;

  if (value >= 1000 * 1000 * 1000) {
    value /= 1000 * 1000 * 1000;
    unit = GIGAOHMS;
  } else if (value >= 1000 * 1000) {
    value /= 1000 * 1000;
    unit = MEGAOHMS;
  } else if (value >= 1000) {
    value /= 1000;
    unit = KILOOHMS;
  } else {
    unit = OHMS;
  }

  return (resistor_value_t){value, unit};
}
