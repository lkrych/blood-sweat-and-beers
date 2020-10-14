#include "resistor_color_duo.h"

int color_code(resistor_band_t r[]) {
    return ((int)r[0] * 10) + (int) r[1];
}
