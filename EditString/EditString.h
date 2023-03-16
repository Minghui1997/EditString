#include <stddef.h>
#include <string.h>

void strslice(char *dest,char *sour,size_t s,size_t e);
void strclear(char *dest);
size_t charindex(char *dest,char fc);
size_t charindex_last(char *dest,char fc);
size_t strindex(char *dest,char *str);
size_t strindex_last(char *dest,char *str);
void strreplace(char *dest,char *repstr,char *sour);