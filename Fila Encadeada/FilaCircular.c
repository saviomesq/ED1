#include <stdio.h>
#define MAX 8
typedef struct{
  int item[MAX];
  int inicio,fim,tam;
}FilaC;
void inicia(FilaC *f);
int insere(FilaC *f, int valor);
int Remove(FilaC *f,int *x);
int main(void) {
  FilaC f1;
  int opcao;
    do
    {
        int valor,retorno;
        printf("\n[1] Iserir elementos na fila\n");
        printf("[2] Retirar elementos na fila\n");
        printf("[3] Verificar o elemento que está na saida da fila\n");
        printf("[4] Mostrar todos os elemenatos da fila\n");
        printf("[5] sair\n");
        scanf("%d",&opcao);
        switch(opcao)
        {
        case 1:
            printf("\nDigite o elemento que deseja inserir: ");
            scanf("%d",&valor);
            retorno=insere(&f1,valor);
            if(retorno==1)
            {
                printf("\nvalor inserido!");
            }
            else
            {
                printf("\n VALOR NAO INSERIDO CAPACIDADE MAXIMA\n");
                printf("\n\n");
            }
            break;

        case 2:
            
                retorno=Remove(&f1,&valor);
                if(retorno==1)
                {
                    printf("\nValor removido com sucesso!");
                    printf("\nValor removido: %d", valor);
                    printf("\n");
                }
                else
                {
                    printf("\nNao ha elementos na fila para remoçao\n");
                }

            break;
        case 3:
            printf("\nValor na saida fa fila: %d", f1.item[f1.inicio]);
            printf("\n");
            break;

        case 4:
            printf("\nElementos da fila:");
            for(int i=f1.inicio; i<f1.fim; i++)
            {
                printf("\n%d",f1.item[i]);
                printf("\n");
            }
            break;
        }
    }
    while(opcao!=5);
  return 0;
}
int insere(FilaC *f, int valor){
  if(f->tam==MAX){
    return 0;
  }
  if(f->fim==MAX)
    f->fim=0;
  f->item[f->fim]=valor;
  f->fim++;
  f->tam++;
  return 1;
}
int Remove(FilaC *f,int *x){
  if(f->tam==0)
    return 0;
  *x=f->item[f->inicio];
  f->inicio++;
  if(f->inicio==MAX)
    f->inicio=0;
  f->tam--;
  return 1;
}
void inicia(FilaC *f){
  f->inicio=f->fim=0;
  f->tam=0;
}
