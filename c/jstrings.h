#ifndef _jstrings_h
#define _jstrings_h

typedef struct String {
    char *str;
    int len;
} String;

String *makeStr(char *cstring);
void freeStr(String *string);

#endif












