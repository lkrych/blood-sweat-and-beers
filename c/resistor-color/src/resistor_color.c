#include "resistor_color.h"

int color_code(resistor_band_t r) {
    return r;
}

int* colors() {
    int i; 
    int *colors = (int*) malloc(sizeof(int));
    for (i=BLACK; i<=WHITE; i++) {
        colors[i] = i;
    }
    return colors;
}
