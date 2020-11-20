#include "grains.h"
#include <stdio.h>
#include <math.h>

#define CHESS_SQUARES 64

uint64_t square(uint8_t index) {
    if (index <= 0) {
        return 0;
    }
    if (index > CHESS_SQUARES) {
        return 0;
    }
    return pow(2, index - 1);
}

uint64_t total(void) {
    uint64_t total = 0;
    for (int i = 0; i < CHESS_SQUARES +1; i++) {
        total += square(i);
    }
    return total;
}
