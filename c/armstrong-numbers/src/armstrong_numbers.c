#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate) {
    int copy_of_candidate, digit;
    int ndigits = 0;
    double armstrong = 0;

    copy_of_candidate = candidate;

    while (copy_of_candidate > 0) {
        copy_of_candidate = copy_of_candidate / 10;
        ndigits += 1;
    }

    copy_of_candidate = candidate;
    while (copy_of_candidate > 0) {
        digit = copy_of_candidate % 10;

        copy_of_candidate = copy_of_candidate / 10;
        armstrong += pow(digit,ndigits);
    }

    if (candidate == armstrong) {
        return true;
    }
    return false;
}
