#ifndef _wordstructs_h
#define _wordstructs_h

#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <dbg.h>

typedef struct defType {
    char id;
    char *abstract;
    char *definition;
} defType;

typedef struct Word {
    char *word;
    int noun;
    int verb;
    int adj;
    int adv;
    List *indexes;
    List *definitions;
} Word;

defType *makeDef(char *def);
Word *makeWord(char *word);
void freeDefType(defType *def);
void freeWord(Word *word);

#endif














