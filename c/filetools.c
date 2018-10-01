#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dbg.h>
#include <filetools.h>

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
    debug("Function Started");
    if(bot - top <= 2) {
        return NULL;
    }
    long mid = ((bot - top) / 2) + top;
    long offset = findBegin(file, mid);
    fseek(file, offset, SEEK_SET);
    debug("Fseek Complete");
    int count = 0;
    while(fgetc(file) != '\n') {
        count++;
    }
    char middle[count];
    fseek(file, offset, SEEK_SET);
    int move = 0;
    int temp = 0;
    debug("Assigning Middle");
    while(temp != '\n' && move < count) {
        temp = fgetc(file);
        middle[move] = temp;
        move++;
    }
    middle[move] = '\0'; 
    debug("Middle Assigned");

    if(word[place] == 0 && middle[place] == 32) {
        char *value = malloc(sizeof(middle));
        value = strdup(middle);
        debug("Found Word");
        return value;
    } else {
        debug("Did not find word");
        for(count = 0; count < place; count++) {
            if( word[count] != middle[count] ) {
                debug("Moving back a place");
                return binsearch(file, word, top, bot, (place - 1));
            }
        }   
        if( word[place] < middle[place] ) {
            debug("Word is less than middle");
            return binsearch(file, word, top, mid, place);
        } else if( word[place] > middle[place] ) {
            debug("Word is greater than middle");
            return binsearch(file, word, mid, bot, place);
        } else if( word[place] == middle[place] ) {
            debug("Word is equal to middle");
            return binsearch(file, word, top, bot, (place + 1));
        } else {
            debug("Something is deeply wrong");
            printf("This shouldn't happen");
            return NULL;
        }
        debug("End of decision tree");
        return NULL;
    }
    debug("End of Function");
    return NULL;
}

char *File_search(char *filename, char *word)
{
    FILE *file = fopen(filename, "r");
    fseek(file, 0L, 2);
    long top = 0;
    long bot = ftell(file);
    char *result = malloc(sizeof(char*));
    result = binsearch(file, word, top, bot, 0);
    fclose(file);
    return result;
}

char *File_readLine(char *filename, long offset)
{
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
    char *result = malloc(sizeof(char *));
    result = strdup(line);
    fclose(file);
    return result;
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







