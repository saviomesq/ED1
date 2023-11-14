#include <stdio.h>
#define MAX 20
typedef struct{
  int item[MAX];
  int inicio,fim;
}Fila;
void inicia(Fila *p);
int insere(Fila *p,int x);
int Remove(Fila *f, int *x);
int main(void) {
  Fila p;
  int aux=0;
  inicia(&p);
  int valor,retorno;
   for(int i=0;i<3;i++){
    printf("\nDigite um valor para empilhar: ");
    scanf("%d",&valor);
    retorno=insere(&p,valor);
     if(retorno==1)
       printf("\nValor inserido com sucesso!");
     else  
       printf("\nFila cheia!");
  }
 for(int i=0;i<4;i++){
   do{
      retorno=Remove(&p,&valor);
      if(valor>0){
        aux+=valor;
      }
      
  }while(valor<0);
   
 } 
  
printf("\n\nA soma dos numeros positivos eh de: %d",aux);

  
  return 0;
}
void inicia(Fila *p){
  p->inicio=p->fim=0;
}
int insere(Fila *p,int x){
  if(p->fim==MAX){
    return 0;
  }
  else{
    p->item[p->fim]=x;
    p->fim++;
    return 1;
  }
}
int Remove(Fila *f, int *x)
{
    if(f->inicio==f->fim)
        return 0;
    else
    {
        *x=f->item[f->inicio];
        f->inicio++;
        return 1;
    }
}
