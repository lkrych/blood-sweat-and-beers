#include "rna_transcription.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char bio_translation(char c) {
    c = toupper(c);
    switch(c) {
        case 'G':
            return 'C';
        case 'C':
            return 'G';
        case 'T':
            return 'A';
        case 'A':
            return 'U';
        default:
            //special case of invalid nucleotide
            return ' ';
    }
}

char *to_rna(const char *dna) {
    if (dna == NULL) {
        return NULL;
    }
    char* rna = (char*) malloc(strlen(dna));
    for(int i = 0; i < (int)strlen(dna); i++) {
        char c = bio_translation(dna[i]);
        if (strcmp(&c, " ") == 0) {
            return NULL;
        }
        rna[i] = c;
    }
    return rna;
}
