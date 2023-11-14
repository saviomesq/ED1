#include <stdio.h>
typedef struct no{
  int quantidade, codigo;
  float preco;
  struct no *prox;
}noptr;
noptr *inicio;
void insere_lista(noptr *novo,int qntd, int cdg, float valor);
void desconto(int desconto);
void lista_todos();
void Lista_500();

int main(void) {
  int opcao,quantidade,codigo,salve=1,desc;
  float preco;
  inicio=NULL;
  noptr *info;
  do{
    printf("[1] Inserir produto\n");
    printf("[2] Valor de desconto\n");
    printf("[3] Mostrar produtos\n");
    printf("[4] Mostrar produtos com mais de 500 qntds\n");
    printf("[5] sair\n");
    printf("opcao: ");
    scanf("%d",&opcao);
    if(opcao==1){
      printf("\nDigite a quantidade do produto: ");
      scanf("%d",&quantidade);
      printf("\nDigite o codigo do produto: ");
      scanf("%d",&codigo);
      printf("\nDigite o valor do produto: ");
      scanf("%f",&preco);
      info=(struct no *) malloc(sizeof(noptr));
             if(!info){
                printf("\nSem memoria!!");
                return;
             }   

      insere_lista(info,quantidade,codigo,preco);
    }
    else if(opcao==2){
      printf("\nDigite o valor da porcentagem do desconto: ");
      scanf("%d",&desc);
      desconto(desc);
    }
    else if(opcao==3){
      lista_todos();
    }
    else if(opcao==4){
      Lista_500();
    }
    else if(opcao==5){
      break;
    }
  }while(salve!=0);
  return 0;
}
void insere_lista(noptr *novo, int qntd, int cdg, float valor) {
  noptr *p, *ant;
  novo->quantidade = qntd;
  novo->codigo = cdg;
  novo->preco = valor;
  novo->prox = NULL;
  if (inicio == NULL) {
    inicio = novo;
  } else {
    p = inicio;
    ant = NULL;
    while (p != NULL) {
      ant = p;
      p = p->prox;
    }
    ant->prox = novo;
  }
}

void desconto(int desconto){
  
 if(inicio==NULL){
    printf("\nSem produto para dar desconto!!");
    return;
  }
  noptr *p;
  p=inicio;
  while(p){
    p->preco=(float)p->preco-(p->preco*((float)desconto/100));
    p=p->prox;
  }
  printf("\n\n");
}
void lista_todos(){
  if(inicio==NULL){
    printf("\nLista vazia!!");
    return;
  }
  noptr *p;
  p=inicio;
  while(p){
    printf("\nProdutos: \nCodigo do item: %d Quantidade: %d Preco: %.2f",p->codigo,p->quantidade, p->preco);
    p=p->prox;
  }
  printf("\n\n");
}
void Lista_500(){
  if(inicio==NULL){
    printf("\nLista vazia!!");
    printf("\nNao tem produtdo com mais de 500 qntd.");
    return;
  }
  noptr *p;
  p=inicio;
  while(p){
    if(p->quantidade>=500){
      printf("\nCodigo do item: %d Quantidade: %d Preco: %.2f",p->codigo,p->quantidade, p->preco);
    }
    p=p->prox;
    printf("\n\n");
  }
}
