#include "isogram.h"
#define ALPHA_LEN 26

int alpha_index(char c) {
    const char alphabet[] = {
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
        'g',
        'h',
        'i',
        'j',
        'k',
        'l',
        'm',
        'n',
        'o',
        'p',
        'q',
        'r',
        's',
        't',
        'u',
        'v',
        'w',
        'x',
        'y',
        'z'
    };

    char lowerC = tolower(c);

    for(int i = 0; i < ALPHA_LEN; i++) {
        if (lowerC == alphabet[i]) {
            return i;
        }
    }
    return -1;
}

bool is_isogram(const char phrase[]) {

    //check for NULL pointer  
    if(!phrase) {
        return 0;
    }

    //allocate array for counting indices
    int phrase_alpha[26] = {0};
    
    // iterate through every character in phrase
    // find index and add it to phrase_alpha
    const char* current;    
    for (current = phrase; *current != '\0'; current++) {
        int index = alpha_index(current[0]);
        if (index == -1) {
            continue;
        } else {
            if (phrase_alpha[index] > 0) {
                return false;
            } else {
                phrase_alpha[index] += 1;
            }
        }
    }
    return 1;
}
