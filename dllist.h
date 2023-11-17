#ifndef _DLLIST_H_
#define _DLLIST_H_

typedef struct _dllist_ DLList;
typedef struct _dllnode_ DLLNode;

//criando a lista duplamente encadeada
DLList *dllCreate(void);

//inserir no final da lista
int dllInsertAsLast(DLList *l, void *item);

// inserir primeiro elemento
int dllInsertFirst(DLList *l, void *data);

//pegar primeiro - UTILIZADO NA HORA DE LISTAR
void *dllGetFirst(DLList *l);

//pegar proximo - UTILIZADO NA HORA DE LISTAR
void *dllGetNext( DLList *l);

//pegar proximo - UTILIZADO NA HORA DE LISTAR
void *dllPegarProximo(DLList *l);

//Pegar Primeiro elemento da lista
void *dllPegarPrimeiro(DLList *l);

//remover um elemento especificado
void *dllRemoveSpec (DLList *l, void *key, int (*cmp)(void*,void*));

// consultar um elemento especificado
void *dllQuery(DLList *l, void *key, int (*cmp)(void *, void *));

//destruir a dll
int dllDestroy(DLList *l);

//esvaziar a dll
int dllClear(DLList *l);


#endif