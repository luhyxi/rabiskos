#include "lista.h"
#include <stdlib.h>
#include "chu.h"

// implementação fajuta de lista, usando um vetor de tamanho fixo
//
// deve ser reimplementada como uma lista duplamente encadeada com
//   alocação dinâmica de cada nó.


/* IMPLEMENTAÇÃO ANTIGA!!!! */
//struct _lista {
//  void *dados[50];
//  int num;
//  int pos_percurso;
// };


/*Nova Implementação*/
typedef struct lista *Lista;
typedef struct nodo *nodo;
typedef struct _str *Str;


struct lista {
  int num;    // número de elementos na lista
  nodo *prim; // nó que contém o primeiro elemento da lista
  nodo *ult;  // nó que contém o último elemento da lista
  };


struct nodo {
  Str info; // a informação que é mantida por este nó
  nodo *prox;  // ponteiro para o nó seguinte
  nodo *ant;   // ponteiro para o nó anterior
 };


//
// CRIA A PORRA DA LISTA
// 
Lista lista_cria(void)
{
  Lista self = malloc(sizeof(*self));
  if (self == NULL) return NULL;
  self->num = 0;
  self->ult = 0;
  return self;
}


//
// CRIA A PORRA DO NODO
//
static nodo *cria_nodo(Str info, nodo *prox)
  {
    nodo *no = malloc(sizeof(nodo));
    if (no != NULL) {
    no->info = info;
    no->prox = prox;
    }
     return no;
   }


void lista_destroi(Lista self)
{
  if (self ->prim != NULL)
  {
    nodo* ult_zero = self -> ult;
    free (self);
    ult_zero
  }
}

int lista_nelem(Lista self)
{
  if (self == NULL) return NULL;
  return self->num;
}

static nodo  *lista_elem_pos(Lista self, int pos)
{
  if (self == NULL) return NULL;
  nodo *no = self -> prim;
  
  int p = 0;
  while (no != NULL && p < pos) {
    no = no ->prox;
    p++;
  }
  return no;
}

void lista_insere_pos(Lista self, nodo no, int pos)
{
  if (self == NULL) return NULL;
  nodo *no = self -> prim;

  if (pos == self -> prim) lista_insere_inicio(pos, no), return;

  if (pos < 0 || pos > self->num) return;
  if (self->num >= 50) return;
  for (int i = self->num; i > pos; i--) {
    self->dados[i] = self->dados[i-1];
  }
  self->dados[pos] = dado;
  self->num++;
}

void lista_insere_inicio(Lista self, nodo no)
{
  lista_insere_pos(self, dado, 0);
}

void lista_insere_fim(Lista self, void *dado)
{
  lista_insere_pos(self, dado, -1);
}

void *lista_remove_pos(Lista self, int pos)
{
  if (self == NULL) return NULL;
  if (pos < 0) pos = self->num + pos;
  if (pos < 0 || pos >= self->num) return NULL;
  void *dado = self->dados[pos];
  self->num--;
  for (int i = pos; i < self->num; i++) {
    self->dados[i] = self->dados[i+1];
  }
  return dado;
}

void *lista_remove_inicio(Lista self)
{
  return lista_remove_pos(self, 0);
}

void *lista_remove_fim(Lista self)
{
  return lista_remove_pos(self, -1);
}

void *lista_proximo(Lista self)
{
  if (self == NULL) return NULL;
  if (self->pos_percurso >= self->num) return NULL;
  return self->dados[self->pos_percurso++];
}

void *lista_percorre(Lista self)
{
  if (self == NULL) return NULL;
  self->pos_percurso = 0;
  return lista_proximo(self);
}
