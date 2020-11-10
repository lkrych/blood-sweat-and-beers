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
            printf("%c is an invalid DNA nucleotide -- Skipping", c);
            return ' ';
    }
}

char *to_rna(const char *dna) {
    if (dna == NULL) {
        return NULL;
    }
    char* rna = (char*) malloc(strlen(dna));
    for(int i = 0; i < (int)strlen(dna); i++) {
        rna[i] = bio_translation(dna[i]);
    }
    return rna;
}
