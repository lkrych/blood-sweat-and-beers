#include "beer_song.h"
#include <stdio.h>

#define BOTTLES "bottles"
#define BOTTLE "bottle"

void verse(char *buffer, unsigned int verse_number) {
    char* prev_n;
    char* prev_bottles;
    char* now_n;
    char* now_bottles;

    if (verse_number <= 2) {
        prev_n = itoa(verse_number, prev_n, 10);
        now_n = itoa(verse_number - 1, prev_n, 10);
        prev_bottles = BOTTLES;
        if (verse_number == 2) {
            now_bottles = BOTTLE;
        } else {
            now_bottles = prev_bottles;
        }
    } else if (verse_number == 1) {
        prev_n = itoa(verse_number, prev_n, 10);
        now_n = "no more";
        prev_bottles = BOTTLE;
        now_bottles = BOTTLES;
    }
    
    buffer = sprintf(buffer, 
        "%s %s of beer on the wall, %s %s of beer.\nTake one down and pass it around, %s %s of beer on the wall.\n",
        prev_n, prev_bottles, prev_n, prev_bottles, now_n, now_bottles);
}
void sing(char *buffer, unsigned int starting_verse_number,
          unsigned int ending_verse_number) {

 }