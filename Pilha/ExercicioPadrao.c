#include <stdio.h>
typedef struct{
  int topo;
  int dados[10];
}PILHA;
void empilhar(PILHA *p, int x);
int desimpilhar(PILHA *p);

int main(void) {
  int valor,x,soma=0;
  PILHA p1;
  p1.topo=-1;
  for(int i=0;i<3;i++){
    printf("\nDigite um valor para empilhar: ");
    scanf("%d",&valor);
    empilhar(&p1, valor);
  }
  do{
    
    x=desimpilhar(&p1);
    if(x>0){
      soma+=x;
    }
  }while(x<0);

    do{
    
    x=desimpilhar(&p1);
    if(x>0){
      soma+=x;
    }
  }while(x<0);

    do{
    
    x=desimpilhar(&p1);
    if(x>0){
      soma+=x;
    }
  }while(x<0);

    do{
    
    x=desimpilhar(&p1);
    if(x>0){
      soma+=x;
    }
  }while(x<0);

  printf("\n\nA soma dos numeros positivos eh de: %d",soma);
  
  return 0;
}

void empilhar(PILHA *p, int x){
  if(p->topo==2){
    printf("\nPilha cheia");
  }
  else{
    p->dados[++p->topo]=x;
  }
}
int desimpilhar(PILHA *p){
  if(p->topo==-1){
    printf("\nPilha vazia");
    return -1;
  }
  else{
    return p->dados[p->topo--];
  }
}
