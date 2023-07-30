#include <string.h>

typedef size_t ind_t;

ind_t charindex(char *dest,char c);
ind_t charindex_last(char *dest,char c);
ind_t strindex(char *dest,char *str);
ind_t strindex_last(char *dest,char *str);
void strclear(char *dest);
void strslice(char *dest,char *sour,ind_t slis,ind_t slie);
void strreplace(char *dest,char *repstr,char *str);
void strinsert(char *dest,ind_t insi,char *sour);
void strtrim(char *dest,ind_t trii,size_t tril);