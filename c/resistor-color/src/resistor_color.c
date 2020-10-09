#include "resistor_color.h"

int color_code(resistor_band_t r) {
    return r;
}

resistor_band_t* colors() {
    int i; 
    resistor_band_t *colors = (resistor_band_t*) malloc(sizeof(resistor_band_t));
    for (i=BLACK; i<=WHITE; i++) {
        colors[i] = i;
    }
    return colors;
}
