#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jstrings.h>

String *makeStr(char *cstring)
{
    String *temp = malloc(sizeof(String));

    temp->str = strdup(cstring);

    int i = 0;
    while(cstring[i] != '\0') {
        i++;
    }
    temp->len = i;

    return temp;
}

void freeStr(String *string)
{
    if(string) {
        if(string->str) free(string->str);
        free(string);
    }
}














