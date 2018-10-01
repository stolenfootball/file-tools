#ifndef _filetools_h
#define _filetools_h

#include <string>

long findBegin(FILE *file, long offset);
char *binsearch(FILE *file, char *word, long top, long bot, int place);
std::string searchFile(std::string filename_orig, std::string word);
std::string readLine(std::string filename_orig, long offset);
int findEnd(FILE *file, long offset);

#endif






















