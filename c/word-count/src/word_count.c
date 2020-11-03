#include "word_count.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int word_count(const char *input_text, word_count_word_t *words) {
    int unique_words = 0;
    // c doesn't let you iterate through a const char, 
    // so we need to copy it to another string
    char *copy_input = (char *)malloc(strlen(input_text) * sizeof(char));
    strcpy(copy_input, input_text);
    //split by any whitespace
    char delimit[]=" ,\t\r\n\v\f";
    char* word = strtok(copy_input, delimit);

    // loop through the string to extract all other tokens
    while( word != NULL ) {
        printf( " %s\n", word ); //printing each token
        //check if word exists in words

        for(int i = 0; i < MAX_WORDS; i++) {
            struct word_count_word current_word = words[i];
            //first check the words that already exist
            if (strlen(current_word.text) > 0) {
                int equal = strcmp(current_word.text, word);
                if (equal == 0) {
                    current_word.count += 1;
                    words[i] = current_word;
                    break;
                } else {
                    continue;
                }
            } else {
                strcpy(current_word.text, word);
                current_word.count = 1;
                words[i] = current_word;
                unique_words++;
                break;
            }
        }
        word = strtok(NULL, delimit);
    }

    free(copy_input);
    return unique_words;
}
