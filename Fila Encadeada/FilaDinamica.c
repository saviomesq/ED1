#include <stdio.h>
typedef struct no{
  char nome[20];
  int idade;
  struct no *prox;
}noptr;

noptr *inicio;
void insere_lista(noptr *novo,int idade,char name[]);
void lista_todos();
void remove_lista();


int main(void) {
  int idade = -1;
  char nome[20];
  inicio= NULL;
  noptr *info;
    do{
          printf("\nDigite seu nome:");
          scanf(" %s",&nome);
          printf("\nDigite sua idade:");
          scanf("%d",&idade);
          if(idade!=0){
             info=(struct no *) malloc(sizeof(noptr));
             if(!info){
                printf("\nSem memoria!!");
                return;
             }   
            insere_lista(info,idade,nome);
          }
          
    }while(idade!=0);
 
  lista_todos();
  
  return 0;
}  
void insere_lista(noptr *novo,int idade,char name[]){
  novo->idade=idade;
  strcpy(novo->nome,name);
  if(inicio==NULL){
    novo->prox=NULL;
  }
  else
    novo->prox=inicio;
  inicio=novo;
}
void lista_todos(){
   printf("cheguei");
  if(inicio==NULL){
    printf("\nLista vazia!!");
    return;
  }
  noptr *p;
  printf("entrei");
  p=inicio;
  while(p){
    printf("\nSaida: nome: %s idade: %d",p->nome,p->idade);
    p=p->prox;
  }
  printf("\n\n");
}
void remove_lista(){
  noptr *p;
  if(inicio==NULL){
    printf("\nLista Vazia!!");
    return;
  }
  else{
    //while(inicio=!NULL){
      p=inicio;
      printf("\nNome removido: %s, idade: %d",p->nome,p->idade);
      inicio=p->prox;
      free(p);
   // }
  }
}
