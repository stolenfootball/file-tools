#ifndef _filetools_h
#define _filetools_h

long findBegin(FILE *file, long offset);
char *binsearch(FILE *file, char *word, long top, long bot, int place);
char *File_search(char *filename, char *word);
char *File_readLine(char *filename, long offset);
int findEnd(FILE *file, long offset);

#endif






















