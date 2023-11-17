#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dllist.h"
#define TRUE 1
#define FALSE 0

//TAD DLList
typedef struct _dllnode_{
 void *data;
 struct _dllnode_ *next;
 struct _dllnode_ *prev;
}DLLNode;

typedef struct _dllist_ {
 DLLNode *first;
 DLLNode *cur;
}SLList;

typedef struct _aluno_{
  char nome[30];
  int idade;
  float media;
}Aluno;


//criando a lista simplesmente encadeada
DLList *dllCreate(void){
  SLList *l;
  l = (SLList *) malloc(sizeof(SLList));
  if (l != NULL){
    l -> first = NULL;
    l -> cur = NULL;
    return l;
  }
  return NULL;
}

//inserir no final da fila
int dllInsertAsLast(DLList *l, void *item){
    DLLNode *last;
    if(l != NULL){
        DLLNode *newnode = (DLLNode*)malloc(sizeof(DLLNode));
        if(newnode != NULL){
            newnode->data = item;
            newnode->next = NULL;
            if(l->first != NULL){
                last = l->first;
                while(last->next != NULL){
                  last = last->next;
                }
                last->next = newnode;
            }else{
              l->first = newnode;
            }
            return TRUE;
        }
    }
    return FALSE;
}

// inserir primeiro elemento


int dllInsertFirst(DLList *l, void *data){
  DLLNode *newnode;
  if(l != NULL){
    newnode = (DLLNode *) malloc(sizeof(DLLNode));

    if (newnode != NULL){
      newnode -> data = data;
      newnode -> next = l->first;
      l->first = newnode;
      return TRUE;
    }
  }
  return FALSE;
}



//pegar primeiro - UTILIZADO NA HORA DE LISTAR
void *dllGetFirst(DLList *l){
    void *data;
    if(l !=	NULL){
        if (l->first != NULL){
            data = l->first->data;
            l->cur = l->first;
            return data;
        }
    }
    return NULL;
}


//pegar proximo - UTILIZADO NA HORA DE LISTAR (bugada)
void *dllGetNext( DLList *l){
  if ( l!= NULL ) {
    if ( l->cur != NULL ) {
      l->cur = l->cur->next;
      return l->cur;
      }
  }
  return NULL;
}



//pegar proximo - UTILIZADO NA HORA DE LISTAR
void *dllPegarProximo(DLList *l){
  if(l!=NULL){
   if(l->first !=NULL){
     if(l->cur->next != NULL){
	l->cur = l->cur->next;
	return l->cur->data;
     }
   }
  }
  return NULL;
}


void *dllPegarPrimeiro(DLList *l)
{
    void *data;
    if(l !=	NULL)
    {
        if (l->first != NULL)
        {
            data = l->first->data;
            l->cur = l->first;
            return data;
        }
    }
    return NULL;
}



//remover um elemento especificado
void *dllRemoveSpec (DLList *l, void *key, int (*cmp)(void*,void*)){
  DLLNode *spec, *prev;
  void *data;
  if(l!= NULL){
    if(l->first != NULL){
      spec = l-> first;
      prev = NULL;
      while (spec -> next != NULL && cmp (key, spec -> data ) != TRUE){
        prev = spec;
        spec = spec->next;
      }
    }
    if (cmp(key,spec->data) == TRUE){
      data = spec ->data;
      if (spec == l->first){
        l-> first = spec ->next;
      }else{
        prev -> next = spec -> next;
      }
      free(spec);
      return data;
    }
  }
  return NULL;
}


// consultar um elemento especificado
void *dllQuery(DLList *l, void *key, int (*cmp)(void *, void *)){
    DLLNode *cur;
    if (l != NULL){
      if (l->first != NULL){
        cur = l->first;
        while (cur->next != NULL && cmp(key, cur->data) != TRUE){
          cur = cur->next;
          }
          if (cmp(key, cur->data) == TRUE){
            return cur->data;
          }
      }
  }
  return NULL;
}


//destruir a dll
int dllDestroy(DLList *l){
  if (l != NULL){
    if (l->first == NULL){
      free(l);
      return TRUE;
    }
  }
  return FALSE;
}

//esvaziar a dll
int dllClear(DLList *l){
    DLLNode *cur, *next;
    if(l != NULL)    {
        if(l->first != NULL){
            cur = l->first;
            next = cur->next;
            free(cur);
            while(next != NULL){
                cur = next;
                next = cur->next;
                free(cur);
            }
            l->first = NULL;
            return TRUE;
        }
    }
    return FALSE;
}
