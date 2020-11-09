#include "space_age.h"

const float PLANET_MULTIPLIERS[] = {
   0.2408467,
   0.61519726,
   1.0,
   1.8808158,
   11.862615,
   29.447498,
   84.016846,
   164.79132
};

float convert_planet_age(planet_t planet, int64_t input) {
    float earth_years = (input/SECONDS_IN_DAY) / DAYS_IN_YEAR;
    return earth_years * PLANET_MULTIPLIERS[planet];
}
