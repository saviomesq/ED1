#include <stdio.h>
typedef struct{
  int topo;
  int dados[10];
}PILHA;

void empilhar(PILHA *p, int x);
int desimpilhar(PILHA *p);

int main(void) {
  int opcao;
  PILHA p1;
  p1.topo=-1;
  do{
    printf("\n\n[1] Inserir elemento na pilha: ");
    printf("\n[2] Retirar elemento da pilha: ");
    printf("\n[3] Vereficar elemento no topo da pilha: ");
    printf("\n[4] Mostrar todos os elementos da pilha: ");
    printf("\n[0] Sair: ");
    printf("\nOpcão: ");
    scanf("%d",&opcao);
    if(opcao==1){
      int x;
      printf("\nDigite o numero que deseja inserir: ");
      scanf("%d",&x);
      empilhar(&p1, x);
      
    }
    else if(opcao==2){
     int x= desimpilhar(&p1);
      printf("\nValor desimpilhado: %d",x);
    }
    else if (opcao ==3){
      printf("\n Ultimo valor da pilha:");
      printf("%d",p1.dados[p1.topo]);
    }
    else if(opcao==4){
      for(int i=0;i<=p1.topo;i++){
        printf("%d ", p1.dados[i]);
      }
    }
    
  }while(opcao!=0);

  return 0;
}
void empilhar(PILHA *p, int x){
  if(p->topo==9){
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
  else
    return p->dados[p->topo--];
}
