#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dllist.h"

#define TRUE 1
#define FALSE 0

typedef struct _aluno_{
    char nome[30];
    int matricula;
    float media;
}Aluno;


int cmpAluno(void *key, void *item){
    int *keymat;
    Aluno *colitem;
    keymat = (int *)key;
    colitem = (Aluno *)item;
    if (*keymat == colitem -> matricula)
        return TRUE;
    else{
        return FALSE;
    }
}


int main(){


  DLList *DLAlunos = NULL;
  Aluno *pAluno = NULL;

  int tamColecao;
  int i=0;
  int idade,op, turma, matricula;
  int qtdAlunos=0;
  float media;
  char nome[30];
  int *alunoParaRemover, *key;

  do{
    printf("\n----------MENU------------\n");
    printf("1. Para criar a turma. \n");
    printf("2. Para adicionar um aluno na lista. \n");
    printf("3. Para listar os seus alunos cadastrados. \n");
    printf("4. Para remover um aluno da turma. \n");
    printf("5. Para consultar um aluno. \n");
    printf("6. Para esvaziar a lista. \n");
    printf("7. Para destruir a lista. \n");
    printf("0. Para fechar o menu. ");
    printf("\n----------MENU-------------\n");
    scanf("%d", &op);

      switch(op){
        case 1:
        if(DLAlunos == NULL){
          DLAlunos = dllCreate();
          printf("\n---------------\n");
          printf("lista do RU criada com sucesso!");
        }else{
          printf("A lista do RU já foi criada!");
        }
          break;

        case 2:
        if(DLAlunos != NULL){
              Aluno *pAluno= (Aluno*)malloc(sizeof(Aluno));
              printf("-------------------");
              printf("\nDigite o nome do %d aluno: ", i+1);
              scanf("%s", (pAluno->nome));
              printf("-------------------");
              printf("\nDigite uma matricula para o %d aluno: ", i+1);
              scanf("%d", &pAluno-> matricula);
              printf("-------------------");
              printf("\nDigite a media do %d aluno: ", i+1);
              scanf("%f", &pAluno->media);
              printf("\n");
              if (qtdAlunos == 0){
                if (dllInsertFirst(DLAlunos, pAluno)){
                  printf("Aluno entrou na lista\n");
                  qtdAlunos++;
                }
              }else if(qtdAlunos > 0){
                  if(dllInsertAsLast(DLAlunos, pAluno)){
                  printf("Aluno entrou na lista\n");
                  qtdAlunos++;
                  }
                }else{
                  printf("Aluno nao esta matriculado");
                }
              }else{
                printf("----------------");
                printf("\nA lista do RU nao foi criada\n");
                printf("----------------");
              }

        break;

        case 3:
        if (DLAlunos!=NULL){
          pAluno = (Aluno *)dllPegarPrimeiro(DLAlunos);
          if(pAluno!=NULL && DLAlunos != NULL){
              int i=1;
              while(pAluno != NULL){
                printf("--------%dº da lista----------", i);
                printf("\nAluno: %s\nMatricula: %d\nMedia: %.2f\n"
                    , (pAluno->nome),(pAluno->matricula), (pAluno->media));
                pAluno = (Aluno *)dllPegarProximo(DLAlunos);
                i++;
            }
          }else{
              printf("\n----------------");
              printf("\nNao tem ninguem na lista\n");
              printf("----------------");
          }
        }else{
           printf("----------------");
           printf("\nFila não existe\n");
           printf("----------------");
        }
        break;

        case 4:
        if (DLAlunos != NULL)
        {
          Aluno *removido;
          printf("\n----------------\n");
          printf("Digite a matricula do aluno: ");
          scanf("%d", &matricula);
          removido = (Aluno*)dllRemoveSpec(DLAlunos, (void *)&matricula, cmpAluno);
          if (removido != NULL) // Aluno é removido da coleção.
          {
            printf("\nAluno removido.\n");
          }
          else
          {
            printf("\nAluno nao encontrado na lista.\n\n");
          }
         // free(pAluno);
        }
        else
        {
          printf("----------------");
          printf("\nFila não existe\n");
          printf("----------------");
        }
        break;

          break;

        case 5:
        if (DLAlunos!= NULL)
        {
            printf("Digite a matricula do aluno: ");
            scanf("%d", &matricula);
            pAluno = dllQuery(DLAlunos, (void *)&matricula, cmpAluno);
            if (pAluno != NULL)
            {
                printf("\nO aluno esta na lista do RU\n");
                printf("----DADOS DO ALUNO-----\n");
                printf("Nome: %s\n", pAluno -> nome);
                printf("Matricula: %d\n", pAluno -> matricula);
                printf("Media: %.3f\n", pAluno -> media);
            }
            else
            {
                printf("\nO aluno nao esta na lista do RU\n");
            }
        }
        else
        {
            printf("----------------");
            printf("\nLista não existe\n");
            printf("----------------");
        }
            break;

        case 6:
        if(DLAlunos!=NULL){
            if(dllClear(DLAlunos)){
                pAluno = NULL;
                printf("lista esta esvaziada");
            }else{
                printf("A lista já está vazia\n");
            }
        }else{
          printf("----------------");
          printf("\nLista não existe\n");
          printf("----------------");
        }
        break;
        case 7:
        if (DLAlunos!=NULL){
          if(dllDestroy(DLAlunos)== 1){
            printf("Turma fechada");
            DLAlunos = NULL;
          }else{
            printf("A lista nao pode fechar, pois ha alunos na lista");
            }
        }else{
          printf("----------------");
          printf("\nLista não existe\n");
          printf("----------------");
        }
        break;
        case 0:
          printf("-------------------------");
          printf("\nObrigado por utilizar o programa! \n");
          printf("-------------------------");
          break;
        default:
          printf("opção invalida, tente novamente!");
          break;
      }
    }while(op != 0);
  return 0;
}

