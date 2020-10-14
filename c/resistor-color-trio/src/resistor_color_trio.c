#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t r[]) {
    resistor_value_t res;
    res.value = ((int)r[0] * 10) + (int) r[1];
    
    int ohms_val = pow(10, (int) r[2]);
    res.value = res.value * ohms_val;
    
    if (res.value >= 1000) {
        res.value = res.value/1000;
        res.unit = KILOOHMS;
    } else {
        res.unit = OHMS;
    }
    
    return res;
}
