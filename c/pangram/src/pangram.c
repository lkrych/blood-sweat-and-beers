#include "pangram.h"

bool is_pangram(const char *sentence) {
    if (sentence == NULL) {
        return false;
    }

    const int ALPHA_LEN = 26;
    int alpha[ALPHA_LEN];


    // iterate through sentence and fill in the chars in alpha array
    for(int i = 0; i < (int)strlen(sentence); i++) {
        char c = sentence[i];
        if (isalpha(c)) {
            c = tolower(c);
            int idx = c - 'a';
            printf("%c - %d  \n", c, idx);
            alpha[c - 'a'] = 1;
        } else {
            continue;
        }
    } 
    // iterate through alpha array and check if the char has been set
    for (int i = 0; i < ALPHA_LEN; i++) {
        if (alpha[i] == 0) {
            return false;
        }
    }
    return true;
}
