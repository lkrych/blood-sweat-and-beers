#include "word_count.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int word_count(const char *input_text, word_count_word_t *words) {
    int unique_words = 0;
    int word_count = 0;
    // c doesn't let you iterate through a const char, 
    // so we need to copy it to another string
    char *copy_input = (char *)malloc(strlen(input_text) * sizeof(char));
    strcpy(copy_input, input_text);
    //split by any whitespace
    char delimit[]=" \t\r\n\v\f,:!&@$%^&.";
    char* word = strtok(copy_input, delimit);

    // loop through the string to extract all other tokens
    while( word != NULL ) {
        word_count++;
        //lowercase all characters in word
        for (int i = 0; word[i]; i++){
            if (isdigit(word[i])) {
                continue;
            }
            word[i] = tolower(word[i]);
        }

        //strip quotes from word
        int first_quote = (word[0] == '\'');
        int last_quote = (word[strlen(word) - 1] == '\'');

        if (first_quote == 1 && last_quote == 1) {
            for (int i = 1; i < (int)strlen(word) - 1; i++) {
                word[i-1] = word[i];
            }
            word[strlen(word) - 2] = '\0';
        }
        
        //check if word obeys max_length rule
        if (strlen(word) > MAX_WORD_LENGTH) {
            unique_words = EXCESSIVE_LENGTH_WORD;
            break;
        }

        if (unique_words >= 20) {
            unique_words = EXCESSIVE_NUMBER_OF_WORDS;
        }

        // check if word exists in words
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
