#include <stdio.h>
#define MAX 5
typedef struct
{
    int item[MAX];
    int inicio,fim;
} Fila;

void inicia(Fila *f);
int insere(Fila *f, int x);
int RemoveTroca(Fila *f, int *x);
int Remove(Fila *f, int *x);

int main(void)
{
    int opcao;
    Fila f1;
    inicia(&f1);
    do
    {
        int valor,retorno,opcao;
        printf("\n[1] Iserir elementos na fila\n");
        printf("[2] Retirar elementos na fila\n");
        printf("[3] Verificar o elemento que está na saida da fila\n");
        printf("[4] Mostrar todos os elementos da fila\n");
        printf("[5] sair\n");
        scanf("%d",&opcao);
        switch(opcao)
        {
        case 1:
            printf("\nDigite o elemento que deseja inserir: ");
            scanf("%d",&valor);
            retorno=insere(&f1,valor);
            if(retorno==1)
            {
                printf("\nvalor inserido!");
            }
            else
            {
                printf("\n VALOR NAO INSERIDO CAPACIDADE MAXIMA\n");
                printf("\n\n");
            }
            break;

        case 2:
            printf("\nRetirar com troca [1]");
            printf("\nRetirar sem troca [2]");
            printf("\nopcao: ");
            int salve;
            scanf("%d",&salve);
            if(salve==1)
            {
                retorno=RemoveTroca(&f1,&valor);
                if(retorno==1)
                {
                    printf("\nValor removido com sucesso!");
                    printf("\nValor removido: %d", valor);
                    printf("\n");
                }
                else
                {
                    printf("\nNao ha elementos na fila para remoçao\n");
                }
            }
            else
            {
                retorno=Remove(&f1,&valor);
                if(retorno==1)
                {
                    printf("\nValor removido com sucesso!");
                    printf("\nValor removido: %d", valor);
                    printf("\n");
                }
                else
                {
                    printf("\nNao ha elementos na fila para remoçao\n");
                }
            }

            break;
        case 3:
            printf("\nValor na saida fa fila: %d", f1.item[f1.inicio]);
            printf("\n");
            break;

        case 4:
            printf("\nElementos da fila:");
            for(int i=0; i<f1.fim; i++)
            {
                printf("\n%d",f1.item[i]);
                printf("\n");
            }
            break;


        }
    }
    while(opcao!=5);



    return 0;
}
void inicia(Fila *f)
{
    f->inicio=f->fim=0;
}
int insere(Fila *f, int x)
{
    if(f->fim==MAX)
    {
        return 0;
    }
    else
    {
        f->item[f->fim]=x;
        f->fim++;
        return 1;
    }
}
int RemoveTroca(Fila *f, int *x)
{
    if(f->inicio==f->fim)
    {
        return 0;
    }
    else
    {
        *x=f->item[f->inicio];
        for(int i=0; i<f->fim; i++)
        {
            f->item[i]=f->item[i+1];
        }
        f->fim--;
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
