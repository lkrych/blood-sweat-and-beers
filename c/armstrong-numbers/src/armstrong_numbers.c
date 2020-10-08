#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate) {
    int copy_of_candidate, digit, ans;
    int ndigits = 0;
    double armstrong = 0;

    copy_of_candidate = candidate;

    ndigits = floor(log10(candidate)) + 1;

    while (copy_of_candidate > 0) {
        digit = copy_of_candidate % 10;

        copy_of_candidate = copy_of_candidate / 10;
        armstrong += pow(digit,ndigits);
    }

    ans = candidate == armstrong ? true : false;
    return ans;
}
