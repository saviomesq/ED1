#include <stdio.h>
#include <string.h>
typedef struct no{
    char nome[30];
    float salario;
    struct no *prox;
}noptr;
noptr *inicio=NULL;
void insere_lista(noptr *novo,char name[], float din);
void lista_todos();
void MaisRem();
void mediaSalarial();

int main(void) {
  int opcao,salve=1;
  float preco;
  noptr *info;
  char nome[30];
  float dinheiro;
  do{
    printf("[1] Cadastrar funcionario\n");
    printf("[2] Mostrar funcionario mais remunerado\n");
    printf("[3] Mostrar media salarial\n");
    printf("[4] Mostrar funcionario atraves de salario\n");
    printf("[5] sair\n");
    printf("opcao: ");
    scanf("%d",&opcao);
    if(opcao==1){
      printf("\nDigite o nome do funcionario: ");
      scanf("%s",&nome);
      printf("\nDigite o salario do funcionario: ");
      scanf("%f",&dinheiro);
      while (getchar() != '\n')
      info=(struct no *) malloc(sizeof(noptr));
             if(!info){
                printf("\nSem memoria!!");
                return;
             }   
      insere_lista(info,nome,dinheiro);
      
    }
    else if(opcao==2){
      MaisRem();
    }
    else if(opcao==3){
      mediaSalarial();
    }
    else if(opcao==4){
   
    }  
    else if(opcao==5){
      break;
    }
  }while(salve!=0);
  return 0;
}

void insere_lista(noptr *novo,char nome[], float din){
  noptr *p,*ant;
  strcpy(novo->nome, nome);
  novo->salario=din;
  if(inicio==NULL){
    inicio=novo;
  }
  else{
    p=inicio;
    ant=NULL;
    while(p!=NULL){
      ant=p;
      p=p->prox;
    }
    ant->prox = novo;
  }
}
void MaisRem(){
  if(inicio==NULL){
    printf("\nLista vazia!!");
    printf("\nNao tem funcionario cadastrado.");
    return;
  }
  noptr *p;
  p=inicio;
  float maiorSalario;
  char pessoa[30];
  while(p){
    if(p->salario>maiorSalario){
      maiorSalario=p->salario;
      strcpy(pessoa,p->nome);
    }
    p=p->prox;
  }
  printf("\n%s ganha %f reais por mes. Eh a pessoa com maior salario!!!",pessoa,maiorSalario);
}
void mediaSalarial(){
  if(inicio==NULL){
    printf("\nLista vazia!!");
    printf("\nNao tem funcionario cadastrado.");
    return;
  }
  noptr *p;
  p=inicio;
  float media;
  int cont=0;
  while(p){
    media=p->salario;
    cont++;
    p=p->prox;
  }
  printf("\n A media salarial dos funcionarios eh de: %f",(media/cont));
}
