#include <stddef.h>
#include <string.h>

typedef size_t ind_t;

void strslice(char *dest,char *sour,ind_t s,ind_t e);
void strclear(char *dest);
ind_t charindex(char *dest,char c);
ind_t charindex_last(char *dest,char c);
ind_t strindex(char *dest,char *str);
ind_t strindex_last(char *dest,char *str);
void strreplace(char *dest,char *repstr,char *str);