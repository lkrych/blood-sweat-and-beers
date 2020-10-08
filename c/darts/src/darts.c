#include "darts.h"

int score(struct coordinate_t dart_pos) {
    float radius;

    // a^2 + b^2 = c^2
    radius = sqrtf(powf(dart_pos.x, (float) 2) + powf(dart_pos.y, (float) 2));

    if (radius > 10) {
        return 0;
    } else if (radius > 5) {
        return 1;
    } else if (radius > 1) {
        return 5;
    } 
    return 10;
}
