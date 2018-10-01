#include <wordstructs.h>
#include <string.h>

defType *makeDef(char *def)
{
    defType *temp = malloc(sizeof(defType));
    temp->abstract = malloc(sizeof(char *));
    temp->definition = malloc(sizeof(char *));
    
    temp->definition = strdup(def);

    return temp;
}

Word *makeWord(char *word)
{
    Word *temp = malloc(sizeof(Word));
    temp->definitions = List_create();
    temp->word = strdup(word);

    return temp;
}

void freeDefType(defType *def)
{
    if(def) {
        if(def->definition) free(def->definiton);
        if(def->abstract) free(def->abstract);
        free(def);
    }
}

void freeWord(Word *word)
{
    if(word) {
        if(word->definitions) List_clear_destroy(word->definitions);
        free(word);
    }
}


















