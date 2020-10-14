#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H
#include <stdlib.h>
#include <stdio.h>

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

int color_code(resistor_band_t r[]);

#endif
