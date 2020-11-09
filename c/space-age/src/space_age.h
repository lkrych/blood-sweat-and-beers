#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>

#define DAYS_IN_YEAR 365.25
#define SECONDS_IN_DAY 86400

typedef enum planet {
   MERCURY,
   VENUS,
   EARTH,
   MARS,
   JUPITER,
   SATURN,
   URANUS,
   NEPTUNE,
} planet_t;

float convert_planet_age(planet_t planet, int64_t input);

#endif
