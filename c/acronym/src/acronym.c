#include "acronym.h"

char *abbreviate(const char *phrase) {
    // catch NULL pointer or empty string
    if (!phrase || strlen(phrase) == 0) {
        return NULL;
    }
    //allocate non_constant so we can use strtok to split the phrase
    //copy phrase newly-allocated memory
    char *non_constant_phrase = malloc(strlen(phrase) * sizeof(char));
    strcpy(non_constant_phrase, phrase); 

    //use strtok to break up the phrase with a delimiter
    char *delim = " ";
    char *ptr = strtok(non_constant_phrase, delim);

    // acronym could at most be of length strlen(phrase)
    int acr_idx = 0;
    char *acronym = malloc(strlen(phrase) * sizeof(char));

    //iterate through the space separated words
	while(ptr != NULL)
	{
		acronym[acr_idx] = toupper(ptr[0]);
        acr_idx++;
        ptr = strtok(NULL, delim);
	}
    acronym[acr_idx] = '\0';
    free(non_constant_phrase);
    return acronym;
}
