#include <stdio.h>
#include <string.h>
typedef struct no
{
    char name[30];
    int idade;
    struct no *anterior;
    struct no *proximo;
} noptr;

void insere_lista(noptr **inifunc, noptr *novo, char nick[], int age);
void remove_lista(noptr **inifunc);
void lista_todos(noptr *inifunc);
void pesquisa(noptr *inifunc);


int main(void)
{
    char nome[30];
    int idade = 1,o;
    noptr *inicio;
    inicio = NULL;
    noptr *info;

    do
    {
        printf("\n1 - Inserir no inicio\n");
        printf("2 - Mostrar todos\n");
        printf("3 - Apagar o primeiro elemento da lista\n");
        printf("4 - Enviar um nome para a funcao\n");
        printf("5 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &o);

        switch (o)
        {
        case 1:
            info= (struct no *) malloc(sizeof(noptr));
            if(!info)
            {
                printf("\nSem espaco na memoria!");
                return;
            }
            printf("\nDigite seu nome: ");
            scanf("%s",&nome);
            printf("\nDigite sua idade: ");
            scanf("%d",&idade);
            insere_lista(&inicio,info,nome,idade);
            break;
        case 2:
            lista_todos(inicio);
            break;
        case 3:
            remove_lista(&inicio);
            break;
        case 4:
            pesquisa(inicio);
            break;
        case 5:
            printf("Saindo...");
            break;
        default:
            printf("Opcao invalida! Digite uma das opcoes: \n\n");
            break;
        }

    }
    while(o!=4);

    return 0;
}

void insere_lista(noptr **inifunc, noptr *novo, char nick[], int age)
{
    strcpy(novo->name,nick);
    novo->idade=age;
    novo->anterior=NULL;
    if(*inifunc==NULL)
    {
        novo->proximo= NULL;
    }
    else
    {
        novo->proximo=*inifunc;
        (*inifunc)->anterior=novo;
    }
    *inifunc=novo;
}
void remove_lista(noptr **inifunc)
{

    noptr *p;
    if(*inifunc==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    else
    {
        p=*inifunc;
        printf("\n->Pessoa removida:");
        printf("\n\nNome: %s Idade: %d",p->name,p->idade);
        if((*inifunc)->proximo==NULL)
        {
            *inifunc=NULL;
        }
        else
        {
            *inifunc=p->proximo;
            (*inifunc)->anterior=NULL;
        }
        free(p);
    }
}
void lista_todos(noptr *inifunc)
{
    if(inifunc==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p= inifunc;
    while(p)
    {
        printf("\nNome: %s Idade: %d",p->name,p->idade);
        p=p->proximo;
    }
    printf("\n\n");
}
void pesquisa(noptr *inifunc)
{
    int flag = 0;
    char pesquisa[30];
    printf("\nDigite o nome desejado: ");
    scanf("%s",&pesquisa);
    if(inifunc==NULL)
    {
        printf("\nLista Vazia!");
        return;
    }
    noptr *p;
    p=inifunc;
    while(p)
    {
        if(p->name==pesquisa){
          p->idade+= 10;
          flag=1;
        }
    }
    if(flag==1){
        printf("\nA pessoa %s evelheceu 10 anos!!", pesquisa);
    }
    else
        printf("\nNome não encontrado!");
    printf("\n\n");
}


