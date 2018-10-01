#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filetools.h"

#include <string>


long findBegin(FILE *file, long offset)
{
    fseek(file, offset, SEEK_SET);
    int end = 1;
    while( end != '\n' ) {
        end = fgetc(file);
        offset = offset - 1;
        fseek(file, offset, SEEK_SET);
    }
    offset = offset + 2;
    return offset;
}

char *binsearch(FILE *file, char *word, long top, long bot, int place)
{
    if(bot - top <= 2) {
        return NULL;
    }
    long mid = ((bot - top) / 2) + top;
    long offset = findBegin(file, mid);
    fseek(file, offset, SEEK_SET);
    int count = 0;
    while(fgetc(file) != '\n') {
        count++;
    }
    char middle[count];
    fseek(file, offset, SEEK_SET);
    int move = 0;
    int temp = 0;
    while(temp != '\n' && move < count) {
        temp = fgetc(file);
        middle[move] = temp;
        move++;
    }
    middle[move] = '\0'; 

    if(word[place] == 0 && middle[place] == 32) {
        char *value = malloc(sizeof(middle));
        value = strdup(middle);
        return value;
    } else {
        for(count = 0; count < place; count++) {
            if( word[count] != middle[count] ) {
                return binsearch(file, word, top, bot, (place - 1));
            }
        }   
        if( word[place] < middle[place] ) {
            return binsearch(file, word, top, mid, place);
        } else if( word[place] > middle[place] ) {
            return binsearch(file, word, mid, bot, place);
        } else if( word[place] == middle[place] ) {
            return binsearch(file, word, top, bot, (place + 1));
        } else {
            printf("This shouldn't happen");
            return NULL;
        }
        return NULL;
    }
    return NULL;
}

std::string searchFile(std::string filename_orig, std::string wordsearch)
{
    char *filename = filename_orig.c_str();
    char *word = malloc(sizeof(char*));
    word = wordsearch.c_str();
    FILE *file = fopen(filename, "r");
    fseek(file, 0L, 2);
    long top = 0;
    long bot = ftell(file);
    char *result = malloc(sizeof(char*));
    result = binsearch(file, word, top, bot, 0);
    std::string value = result;
    free(result);
    fclose(file);
    return value;
}

std::string readLine(std::string filename_orig, long offset)
{
    char *filename = filename_orig.c_str();
    FILE *file = fopen(filename, "r");
    long begin = findBegin(file, offset);
    int end = findEnd(file, begin);
    int i = 0;
    int temp = 0;
    fseek(file, begin, SEEK_SET);
    char line[end];
    for(i = 0; i < end && i < 498; i++) {
        temp = fgetc(file);
        if(temp) {
            line[i] = temp;
        }
    }
    i++;
    line[i] = '\0';
    std::string value = line;
    fclose(file);
    return value;
}

int findEnd(FILE *file, long place)
{
    long offset = findBegin(file, place);
    fseek(file, offset, SEEK_SET);
    int count = 0;
    while(fgetc(file) != '\n') {
        count++;
    }
    count--;
    return count;
}







