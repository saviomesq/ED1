#include <stdio.h>

typedef struct salve{
  int topo;
  int dados[5];
}PILHA;

void empilha(PILHA *p,int x);
int desimpilha(PILHA *p);

int main(void) {
    int x;
    int aux;
    PILHA p1,p2,p3;
    p1.topo=-1;
    p2.topo=-1;
    p3.topo=-1;
    for(int i=0;i<5;i++){
      printf("Digite um valor: ");
      scanf("%d",&x);
      empilha(&p1,x);
    }
    for(int i=0;i<5;i++){
     aux  = desimpilha(&p1);
     if(aux<100 && aux!=-1){
       empilha(&p2, aux);
     }
     else if(aux != -1){
       empilha(&p3,aux);
     }
    }

  printf("\nPILHA 1: ");
  for(int i=0;i<5;i++){
    printf("\n%d",p1.dados[i]);
  }
  printf("\nPILHA 2: ");
  for(int i = 0; i <= p2.topo; i++){
    printf("%d ", p2.dados[i]); 
  }
    printf("\nPILHA 3: ");
  for(int i = 0; i <= p3.topo; i++){
    printf("%d ", p3.dados[i]); 
  }
  
  return 0;
}
void empilha(PILHA *p,int x){
  if((*p).topo==4){
      printf("\nPilha cheia");
  }
  else{
      (*p).dados[++(*p).topo]=x;
  }
}
int desimpilha(PILHA *p){
  int x;
  if(p->topo==-1){
    printf("\nPilha vazia");
    return -1;
  }
  else
  {
    x=p->dados[p->topo--];
  }
    return x;
}
