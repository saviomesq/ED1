#include <stdio.h>
typedef struct no{
  int dados;
  struct no *prox;
}noptr;
noptr *inicio;
void insere_lista(noptr *novo,int dados);
void remove_lista();
void lista_todos();


int main(void) {
  inicio=NULL;
  noptr *info;
  int valor,opcao;
  do{
          printf("\n[1]- Inserir valor na lista");
          printf("\n[2]- Remover valor na lista");
          printf("\n[3]- Listar valores da lista");
          printf("\n[0]- Sair");
          printf("\nopcao: ");
          scanf("%d",&opcao);
        if(opcao==1){
            printf("\nDigite o valor que deseja inserir: ");
            scanf("%d",&valor);
           info=(struct no *) malloc(sizeof(noptr));
           if(!info){
              printf("\nSem memoria!!");
              return;
           }   
          insere_lista(info,valor);
        }
        else if(opcao==2){
          do{
             remove_lista();
          }while(inicio!=NULL);
        }
        else if(opcao==3){
          
          lista_todos();
        }
        else if(opcao==0){
          
          break;
        }
        
  }while(valor!=0);
  
  return 0;
}


void insere_lista(noptr *novo,int dados){
  noptr *p;
  novo->dados=dados;
  novo->prox=NULL;
  if(inicio==NULL)
    inicio=novo;
  else{
    p=inicio;
    while(p->prox!=NULL)
      p=p->prox;
    p->prox=novo;
  }
}
void remove_lista(){
  noptr *p, *ant;
  if(inicio==NULL){
    printf("\nLista vazia!");
    return;
  }
  else{
    p=inicio;
    ant=p;
    while(p->prox!=NULL){
      ant=p;
      p=p->prox;
    }
    printf("\nValor removido: %d",p->dados);
    ant->prox=NULL;
    free(p);
  }
}
void lista_todos(){
  noptr *p, *ant,*fim;
   if(inicio==NULL){
    printf("\nLista vazia!");
    return;
  }
  else{
    p=inicio;
    ant=p;
    while(p->prox!=NULL){
      ant=p;
      p=p->prox;
    }
    fim=ant;
     printf("\nValor listado: %d",p->dados);
    do{
    p=inicio;
    ant=p;
    while(p->prox!=fim){
      ant=p;
      p=p->prox;
    }
    fim=ant;
      printf("\nValor listado: %d",p->dados);
    }while(fim!=NULL);
    
     
   }
  printf("\n\n");
}
