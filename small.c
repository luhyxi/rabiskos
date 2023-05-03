#include "str.h"
#include <string.h>
#include <stdlib.h>


struct _str {
  char *bytes;
};


Str str_cria(char *s)
{
  Str novo;
  novo = malloc(sizeof(struct _str));
  if (novo != NULL) {
    novo->bytes = malloc(strlen(s)+1);
    if (novo->bytes != NULL) {
      strcpy(novo->bytes, s);
    } else {
      free(novo);
      novo = NULL;
    }
  }
  return novo;
}

int str_tam(Str s)
{
  if (s == NULL) return 0;
  int char_count = 0;
  for (int i = 0; s->bytes[i] != '\0'; i++) {
    if ((s->bytes[i] & 0xC0) != 0x80) { // check for first byte of multi-byte character
      char_count++;
    }
  }
  return char_count;
}

int str_numbytes(Str s)
{
  if (s == NULL) return 0;
  return strlen(s->bytes);
}


#include <assert.h>

int main()
{
  Str s = str_cria("ação");
  printf("%d %d", str_tam(s), str_numbytes(s));
};
