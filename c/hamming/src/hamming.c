#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    if (lhs == NULL || rhs == NULL) {
        return -1;
    }
    // make sure strings are of the same length
    int s_len = strlen(lhs);
    if ((int)strlen(rhs) != s_len) {
        return -1;
    }

    int hamming_distance = 0;
    for (int i = 0; i < s_len; i++) {
        if (strcmp(&lhs[i], &rhs[i]) != 0) {
            hamming_distance++;
        }
    }

    return hamming_distance;
}
