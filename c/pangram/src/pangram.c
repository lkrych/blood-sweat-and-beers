#include "pangram.h"

#define ALPHA_LEN 26

bool is_pangram(const char *sentence) {
    if (sentence == NULL) {
        return false;
    }

    int alpha[ALPHA_LEN] = {0};

    // iterate through sentence and fill in the chars in alpha array
    for(int i = 0; i < (int)strlen(sentence); i++) {
        char c = sentence[i];
        if (isalpha(c)) {
            c = tolower(c);
            int idx = c - 'a';
            alpha[idx] = 1;
        } else {
            continue;
        }
    } 
    printf("after\n");
    // iterate through alpha array and check if the char has been set
    for (int i = 0; i < ALPHA_LEN; i++) {
        if (alpha[i] == 0) {
            return false;
        }
    }
    return true;
}
