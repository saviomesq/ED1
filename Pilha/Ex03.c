#include <stdio.h>
#define MAX 10
typedef struct{
  int topo;
  int dados[MAX];
}PILHA;
void empilha(PILHA *p, int x);
int desimpilha(PILHA *p);
int main(void) {
  int N;
  PILHA p1;
  p1.topo=-1;
  printf("Digite quantos numeros quer digitar: \n");
  scanf("%d",&N); 
  for(int i=0;i<N;i++){
    int x;
    printf("\nDigite um numero: ");
    scanf("%d",&x);
    if(x<100){
      empilha(&p1,x);
    }
    else{
      int k;
      k= desimpilha(&p1);
      printf("\nValor desimpilhado: %d",k);
    }
  }
  for(int i=0; i<= p1.topo; i++){
    printf("%d ", p1.dados[i]);
  }
  return 0;
}

void empilha(PILHA *p, int x){
  if(p->topo==9){
    printf("\nPilha cheia");
  }
  else{
   p->dados[++p->topo]=x;
  }
}
int desimpilha(PILHA *p){
  if(p->topo==-1){
    printf("Pilha está vazia");
    return -1;
  }
  else{
    return p->dados[p->topo--];
  }
}
