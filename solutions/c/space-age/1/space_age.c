#include "space_age.h"
#include <stdint.h>

float age(planet_t planet, int64_t seconds) {
  const int64_t earth_year = 31557600;
  float orbital_period_in_earth_years;

  switch (planet) {
  case MERCURY:
    orbital_period_in_earth_years = 0.2408467;
    break;
  case VENUS:
    orbital_period_in_earth_years = 0.61519726;
    break;
  case EARTH:
    orbital_period_in_earth_years = 1.0;
    break;
  case MARS:
    orbital_period_in_earth_years = 1.8808158;
    break;
  case JUPITER:
    orbital_period_in_earth_years = 11.862615;
    break;
  case SATURN:
    orbital_period_in_earth_years = 29.447498;
    break;
  case URANUS:
    orbital_period_in_earth_years = 84.016846;
    break;
  case NEPTUNE:
    orbital_period_in_earth_years = 164.79132;
    break;
  default:
    return -1.0;
  }

  return seconds / (earth_year * orbital_period_in_earth_years);
}
