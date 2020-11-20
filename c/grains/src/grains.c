#include "grains.h"
#include <math.h>

uint64_t square(uint8_t index) {
    int square = index - 1;
    if (square < 0) {
        return 0;
    }
    if (square > 63) {
        return 0;
    }
    return pow(2, square);
}

uint64_t total(void) {
    uint64_t total = 0;
    for (int i = 0; i < 64; i++) {
        total += square(i);
    }
    return total;
}
