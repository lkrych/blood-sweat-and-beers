#include "nucleotide_count.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *count(const char *dna_strand) {
    if (dna_strand == NULL) {
        return NULL;
    }
    int nt_count[4] = {0, 0, 0, 0};

    for(int i = 0; i < (int) strlen(dna_strand); i++) {
        char nt = dna_strand[i];
        switch(nt) {
            case 'A':
                nt_count[0] += 1;
            case 'C':
                nt_count[1] += 1;
            case 'G':
                nt_count[2] += 1;
            case 'T':
                nt_count[3] += 1;
            default:
                return NULL;
        }
    }
    char temp[24] = "A:%d C:%d G:%d T:%d";
    char* ans = malloc(sizeof(char) * strlen(temp));
    sprintf(ans, temp, nt_count[0], nt_count[1], nt_count[2], nt_count[3]);
    return ans;
}
