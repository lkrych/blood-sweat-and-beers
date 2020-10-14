#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <math.h>

#define OHMS "OHMS"
#define KILOOHMS "KILOOHMS"

typedef enum {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

typedef struct {
    int value;
    char* unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t r[]);

#endif
