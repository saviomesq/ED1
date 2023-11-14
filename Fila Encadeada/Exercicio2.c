#include <stdio.h>
#define MAX 20
typedef struct{
  int item[MAX];
  int inicio,fim;
}Pilha;
void inicia(Pilha *p);
int insere(Pilha *p, int x);
int Remove(Pilha *p, int *x);
int main(void) {
  int N;
  Pilha p;
  int retorno;
  inicia(&p);
  printf("Digite quantos numeros quer digitar: \n");
  scanf("%d",&N); 
  for(int i=0;i<N;i++){
    int x;
    printf("\nDigite um numero: ");
    scanf("%d",&x);
    if(x<100){
      retorno=insere(&p,x);
      if(retorno==1)
        printf("\nValor inserido com sucesso!");
       else
        printf("\n Erro ao inserir valor!");  
    }
    else{
      int valor;
      retorno=Remove(&p,&valor);
      if(retorno==1){
        printf("\nValor removido com sucesso!");
        printf("\n[%d]- Valor removido",valor);
      }
      else
        printf("\nErro ao remover valor!");
        printf("\nNao ha mais elemento na fila!");
    }
  }
  for(int i=p.inicio;i< p.fim;i++){
    printf("\n[%d] numero: %d",i,p.item[i]);
  }
  return 0;
}
void inicia(Pilha *p){
  p->inicio=p->fim=0;
}
int insere(Pilha *p, int x){
  if(p->fim==MAX){
    return 0;
  }
  else{
    p->item[p->fim]=x;
    p->fim++;
    return 1;
  }
}
int Remove(Pilha *p,int *x){
  if(p->fim==p->inicio){
    return 0;
  }
  else{
    *x=p->item[p->inicio];
    p->inicio++;
    return 1;
  }
}
