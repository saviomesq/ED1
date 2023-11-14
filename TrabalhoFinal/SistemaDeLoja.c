#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// o que falta
// arquivo
typedef struct
{
    char rua[30];
    int num;
    char cidade[30];
    char estado[2];
} end;

typedef struct no
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct no2
{
    int cpf;
    char nome[30];
    int telefone;
    end adress;
    data nascimento;
    struct no2 *anterior;
    struct no2 *proximo;
} cliente;

typedef struct no3
{
    int code;
    char descri[100];
    int qntd;
    float preco;
    struct no3 *anterior;
    struct no3 *proximo;
} produto;

typedef struct venda
{
    int codigo_venda;
    int codigo_produto;
    int quantidade_comprada;
    int cpf_cliente;
    struct venda *anterior;
    struct venda *proximo;
} venda;

int verificaCPF(cliente *inicio, int busca);
int verificaCODE(produto *iniciop, int busca);
void cadastrarCliente(cliente **inicio, cliente *novo, cliente x);
void alteraCliente(cliente **inicio, int busca);
void buscaCliente(cliente *inicio, int busca);
void lista_todos_cliente(cliente *inicio);
void removeCliente(cliente **inicio, int cpf, venda *iniciov);
void cadastrarProduto(produto **inicio, produto *novo, produto x);
void alteraProduto(produto **iniciop, int busca);
void buscaProduto(produto *iniciop, int busca);
void lista_todos_produto(produto *inicio);
void removeProduto(produto **iniciop, int cpf, venda *iniciov);
void incluirVenda(cliente *inicio, produto *iniciop, venda **iniciov, int cpf, int codigo);
void alteraVenda(venda **iniciov, produto **iniciop, cliente **inicio, int busca);
void lista_todas_vendas(venda *iniciov);
void removeVenda(venda **iniciov, int code, produto *iniciop);
void buscaVenda(venda *iniciov, int busca);
void menu1();
void menuCliente();
void menuProduto();
void menuVenda();
void menuListagem();
void lista_todos_valor(venda *iniciov, cliente *inicio, produto *iniciop, int valor);
void lista_quantidade(produto *iniciop, int valor);

int main(void)
{
    // FILE *pont_arq;
    int o, busca;
    data dataMain;
    cliente clienteMain, *info, *inicio;
    produto produtoMain, *infop, *iniciop;
    venda *infov, *iniciov;
    inicio = NULL;
    iniciop = NULL;
    do
    {
        menu1();
        scanf("%d", &o);

        switch (o)
        {
        case 1:
            menuCliente();
            scanf("%d", &o);
            int aux, codigo_produto = 0;
            switch (o)
            {
            case 1:
                printf("\n====== Cadastro de cliente ======");
                printf("\nDigite o nome do cliente: ");
                scanf(" %s", clienteMain.nome);
                printf("\nDigite o seu CPF: ");
                scanf("%d", &aux);
                clienteMain.cpf = verificaCPF(inicio, aux);
                printf("\nDigite o seu telefone: ");
                scanf("%d", &clienteMain.telefone);
                printf("\nDigite a sua rua: ");
                scanf(" %s", clienteMain.adress.rua);
                printf("\nDigite o numero de sua casa: ");
                scanf("%d", &clienteMain.adress.num);
                printf("\nDigite a sua cidade: ");
                scanf(" %s", clienteMain.adress.cidade);
                printf("\nDigite o seu estado: ");
                scanf(" %s", clienteMain.adress.estado);
                printf("\nDigite o dia de seu aniversario: ");
                scanf("%d", &aux);
                if (aux > 31 || aux < 1)
                {
                    while (aux > 31 || aux < 1)
                    {
                        printf("\nDia invalido!");
                        printf("\nDigite o dia entre [1 - 30]");
                        printf("\nDia do mes: ");
                        scanf("%d", &aux);
                    }
                }
                clienteMain.nascimento.dia = aux;
                printf("\nDigite o mes de seu aniversario: ");
                scanf("%d", &aux);
                if (aux > 12 || aux < 1)
                {
                    while (aux > 12 || aux < 1)
                    {
                        printf("\nMes invalido!");
                        printf("\nDigite o mes entre [1 - 12]");
                        printf("\nMes do ano: ");
                        scanf("%d", &aux);
                    }
                }
                clienteMain.nascimento.mes = aux;
                printf("\nDigite o ano que nasceu: ");
                scanf("%d", &aux);
                if (aux > 2023 || aux < 1933)
                {
                    while (aux > 2023 || aux < 1933)
                    {
                        printf("\nAno invalido!");
                        printf("\nDigite o ano entre [1933 - 2023]");
                        printf("\nAno: ");
                        scanf("%d", &aux);
                    }
                }
                clienteMain.nascimento.ano = aux;
                info = (struct no2 *)malloc(sizeof(cliente));
                if (!info)
                {
                    printf("\nSem espaco na memoria!");
                    return 0;
                }
                cadastrarCliente(&inicio, info, clienteMain);
                break;
            case 2:
                printf("\n====== Alteracao de cliente ======");
                printf("\nDigite o CPF do cliente que deseja alterar");
                printf("\nCPF: ");
                scanf("%d", &busca);
                alteraCliente(&inicio, busca);
                break;
            case 3:
                printf("\n====== Consulta de cliente ======");
                printf("\nDigite o CPF do cliente que deseja consultar");
                printf("\nCPF: ");
                scanf("%d", &busca);
                buscaCliente(inicio, busca);
                break;
            case 4:
                printf("\n====== Remocao de cliente ======");
                printf("\nDigite o CPF do cliente que deseja REMOVER");
                printf("\nCPF: ");
                scanf("%d", &busca);
                removeCliente(&inicio, busca, iniciov);
                break;
            }
            break;
        case 2:
            menuProduto();
            scanf("%d", &o);
            switch (o)
            {
            case 1:
                printf("\n====== Inclusao de produto ======");
                printf("\nDigite o codigo do produto: ");
                scanf("%d", &aux);
                produtoMain.code = verificaCODE(iniciop, aux);
                printf("\nDigite a quantidade do produto: ");
                scanf("%d", &produtoMain.qntd);
                printf("\nDigite o preco do produto: ");
                scanf("%f", &produtoMain.preco);
                printf("\nDigite uma descricao para o produto: ");
                scanf(" %[^\n]", produtoMain.descri);

                infop = (struct no3 *)malloc(sizeof(produto));
                if (!infop)
                {
                    printf("\nSem espaco na memoria!");
                    return 0;
                }
                cadastrarProduto(&iniciop, infop, produtoMain);
                printf("\n\n");
                break;
            case 2:
                printf("\n====== Alteracao de produto ======");
                printf("\nDigite o codigo do produto: ");
                printf("\nCodigo: ");
                scanf("%d", &busca);
                alteraProduto(&iniciop, busca);
                break;
            case 3:
                printf("\n====== Consulta de produto ======");
                printf("\nDigite o codigo do produto que deseja consultar");
                printf("\nCodigo: ");
                scanf("%d", &busca);
                buscaProduto(iniciop, busca);
                break;
            case 4:
                printf("\n====== Remocao de produto ======");
                printf("\nDigite o codigo do produto");
                printf("\nCodigo: ");
                scanf("%d", &busca);
                removeProduto(&iniciop, busca, iniciov);
            }
            break;
        case 3:
            menuVenda();
            scanf("%d", &o);
            int codg, quantidade, codigo;
            switch (o)
            {
            case 1:
                codigo_produto++;
                printf("\n====== Inclusao de Venda ======");
                printf("\nBem vindo as compras ");
                printf("\nDigite o seu CPF: ");
                scanf("%d", &aux);
                incluirVenda(inicio, iniciop, &iniciov, aux, codigo_produto);
                break;
            case 2:
                printf("\n====== Alteracao de venda ======");
                printf("\nDigite o codigo da venda que deseja alterar");
                printf("\nCodigo: ");
                scanf("%d", &codigo);
                alteraVenda(&iniciov, &iniciop, &inicio, codigo);
                break;
            case 3:
                printf("\n====== Busca de venda ======");
                printf("\nDigite o codigo da venda!");
                printf("\nCodigo: ");
                scanf("%d", &codigo);
                buscaVenda(iniciov, codigo);
                break;
            case 4:
                printf("\n====== Remocao de venda ======");
                printf("\nDigite o codigo da venda!");
                printf("\nCodigo: ");
                scanf("%d", &codigo);
                removeVenda(&iniciov, codigo, iniciop);
                break;
            }
            break;
        case 4:
            menuListagem();
            scanf("%d", &o);
            switch (o)
            {
            case 1:
                lista_todos_cliente(inicio);
                break;
            case 2:
                lista_todos_produto(iniciop);
                break;
            case 3:
                lista_todas_vendas(iniciov);
                break;
            case 4:
                // listar clientes que compraram acima do valor que o usuario digitar
                printf("\n====== Pesquisa ======");
                printf("\nDigite o valor");
                printf("\nValor: ");
                scanf("%d", &codigo);
                lista_todos_valor(iniciov, inicio, iniciop, codigo);
                break;
            case 5:
                // ver quais os produtos que estao com quantidade em estoque menor que o valor que o usuario digitar
                printf("\n====== Pesquisa ======");
                printf("\nDigite a quantidade");
                printf("\nQuantidade: ");
                scanf("%d", &codigo);
                lista_quantidade(iniciop, codigo);
                break;
            }

            break;
        case 0:
            printf("Saindo...");
            break;
        default:
            printf("Opcao invalida! Digite uma das opcoes: \n\n");
            break;
        }

    } while (o != 0);

    return 0;
}

void cadastrarCliente(cliente **inicio, cliente *novo, cliente x)
{
    strcpy(novo->adress.cidade, x.adress.cidade);
    strcpy(novo->adress.estado, x.adress.estado);
    novo->adress.num = x.adress.num;
    strcpy(novo->adress.rua, x.adress.rua);
    novo->cpf = x.cpf;
    novo->nascimento.ano = x.nascimento.ano;
    novo->nascimento.mes = x.nascimento.mes;
    novo->nascimento.dia = x.nascimento.dia;
    strcpy(novo->nome, x.nome);
    novo->telefone = x.telefone;
    novo->proximo = NULL;

    if (*inicio == NULL || x.cpf < (*inicio)->cpf)
    {
        novo->proximo = *inicio;
        if (*inicio != NULL)
        {
            (*inicio)->anterior = novo;
        }
        *inicio = novo;
    }
    else
    {
        cliente *atual = *inicio;
        while (atual->proximo != NULL && x.cpf > atual->proximo->cpf)
        {
            atual = atual->proximo;
        }

        novo->proximo = atual->proximo;
        if (atual->proximo != NULL)
        {
            atual->proximo->anterior = novo;
        }
        novo->anterior = atual;
        atual->proximo = novo;
    }
    printf("\nCliente cadastrado com sucesso!");
}

void alteraCliente(cliente **inicio, int busca)
{
    if (*inicio == NULL)
    {
        printf("\nNão há nenhum cliente cadastrado.\n");
        return;
    }

    cliente *p = *inicio, *aux;
    int o, space;
    char alt[30];

    while (p)
    {
        if (p->cpf == busca)
        {
            printf("\nCliente encontrado!");
            printf("\nNome do cliente: %s", p->nome);
            printf("\nDeseja alterar:");
            printf("\n 1 - Alterar endereço");
            printf("\n 2 - Alterar o aniversário");
            printf("\n 3 - Alterar nome");
            printf("\n 4 - Alterar telefone");
            printf("\nOpção: ");
            scanf("%d", &o);

            switch (o)
            {
            case 1:
                printf("\n====== Atualizando endereco ======");
                printf("\nDigite o novo endereço:\n");
                printf("Digite a rua: ");
                scanf("%s", alt);
                strcpy(p->adress.rua, alt);
                printf("Digite o número da casa: ");
                scanf("%d", &space);
                p->adress.num = space;
                printf("Digite a cidade: ");
                scanf("%s", alt);
                strcpy(p->adress.cidade, alt);
                printf("Digite o estado: ");
                scanf("%s", alt);
                strcpy(p->adress.estado, alt);
                break;
            case 2:
                printf("\n====== Atualizando data de aniversario ======");
                printf("\nDigite o novo aniversário:\n");
                printf("Digite o dia: ");
                scanf("%d", &space);
                p->nascimento.dia = space;
                printf("Digite o mês: ");
                scanf("%d", &space);
                p->nascimento.mes = space;
                printf("Digite o ano: ");
                scanf("%d", &space);
                p->nascimento.ano = space;
                break;
            case 3:
                printf("\n====== Atualizando nome ======");
                printf("\nDigite o novo NOME: ");
                scanf("%s", alt);
                strcpy(p->nome, alt);
                break;
            case 4:
                printf("\n====== Atualizando numero ======");
                printf("\nDigite o novo NÚMERO: ");
                scanf("%d", &space);
                p->telefone = space;
                break;
            }

            return;
        }

        p = p->proximo;
    }

    printf("\nCliente não encontrado.\n");
}

void buscaCliente(cliente *inicio, int busca)
{

    cliente *p;
    int flag = 0;
    if (inicio == NULL)
    {
        printf("\nNão tem ha nenhum cliente cadastrado.");
    }
    p = inicio;
    while (p != NULL)
    {
        if (p->cpf == busca)
        {
            printf("\nCliente encontrado!");
            printf("\nNome do cliente: %s", p->nome);
            printf("\nEndereço\n Rua: %s Numero da casa: %d Cidade: %s Estado: %s", p->adress.rua, p->adress.num, p->adress.cidade, p->adress.estado);
            printf("\nAniversario: %d/%d/%d", p->nascimento.dia, p->nascimento.mes, p->nascimento.ano);
            printf("\nCPF: %d", p->cpf);
            printf("\nTelefone: %d\n\n", p->telefone);
            flag = 1;
        }
        p = p->proximo;
    }
    /*while (p != NULL)
        ;*/
    if (flag == 0)
    {
        printf("\nCliente nao encontrado!!!!");
        printf("\nRevise os dados.");
    }
}

int verificaCPF(cliente *inicio, int busca)
{

    cliente *p;
    int flag = 0, cpfzin;
    if (inicio == NULL)
    {
        return busca;
    }
    p = inicio;
    while (p != NULL)
    {
        if (p->cpf == busca)
        {
            printf("\nJa tem cliente cadastrado com esse CPF");
            printf("\nDigite o seu CPF: ");
            scanf("%d", &cpfzin);
            flag = 1;
            return verificaCPF(inicio, cpfzin);
        }
        p = p->proximo;
    }
    if (flag == 0)
    {
        return busca;
    }
}

void removeCliente(cliente **inicio, int cpf, venda *iniciov)
{
    int flag = 0;
    cliente *p = *inicio;
    venda *p2;
    p2 = iniciov;
    if (*inicio == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    else
    {
        while (p != NULL)
        {
            if (p->cpf == cpf)
            {
                while (p2)
                {
                    if (p2->cpf_cliente == p->cpf)
                    {
                        printf("\nImpossivel remover o cliente!");
                        printf("\nCliente ja esta cadastrado em uma venda");
                        return;
                    }
                    p2 = p2->proximo;
                }
                printf("\n====== Cliente encontrado ======");
                printf("\nNome do cliente: %s", p->nome);
                printf("\nCPF: %d", p->cpf);
                printf("\n================================");
                printf("\nCliente removido com sucesso!!!!");

                if (p == *inicio)
                {
                    *inicio = p->proximo;
                    if (*inicio != NULL)
                        (*inicio)->anterior = NULL;
                }
                else
                {
                    p->anterior->proximo = p->proximo;
                    if (p->proximo != NULL)
                        p->proximo->anterior = p->anterior;
                }

                free(p);
                flag = 1;
                break;
            }
            p = p->proximo;
        }

        if (flag == 0)
        {
            printf("\nCliente nao encontrado!!!!");
            printf("\nRevise os dados.");
        }
    }
}

void lista_todos_cliente(cliente *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    cliente *p;
    p = inicio;
    printf("\n====== Clientes cadastrados ======");
    while (p)
    {
        printf("\n\nNome do cliente: %s", p->nome);
        printf("\nEndereço:\nRua: %s Numero da casa: %d Cidade: %s Estado: %s", p->adress.rua, p->adress.num, p->adress.cidade, p->adress.estado);
        printf("\nAniversario: %d/%d/%d", p->nascimento.dia, p->nascimento.mes, p->nascimento.ano);
        printf("\nCPF: %d", p->cpf);
        printf("\nTelefone: %d\n", p->telefone);
        p = p->proximo;
    }
    printf("\n\n");
}
void cadastrarProduto(produto **inicio, produto *novo, produto x)
{

    novo->code = x.code;
    novo->qntd = x.qntd;
    novo->preco = x.preco;
    strcpy(novo->descri, x.descri);
    novo->proximo = NULL;

    if (*inicio == NULL || x.code < (*inicio)->code)
    {
        novo->proximo = *inicio;
        if (*inicio != NULL)
        {
            (*inicio)->anterior = novo;
        }
        *inicio = novo;
    }
    else
    {
        produto *atual = *inicio;
        while (atual->proximo != NULL && x.code > atual->proximo->code)
        {
            atual = atual->proximo;
        }

        novo->proximo = atual->proximo;
        if (atual->proximo != NULL)
        {
            atual->proximo->anterior = novo;
        }
        novo->anterior = atual;
        atual->proximo = novo;
    }
}
void lista_todos_produto(produto *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    produto *p;
    p = inicio;
    while (p)
    {
        printf("\n");
        printf("\nCodigo do produto: %d", p->code);
        printf("\nQuantidade: %d", p->qntd);
        printf("\nPreco: %.2f", p->preco);
        printf("\nDescricao: %s", p->descri);
        p = p->proximo;
    }
    printf("\n");
}
void buscaProduto(produto *iniciop, int busca)
{

    produto *p;
    int flag = 0;
    if (iniciop == NULL)
    {
        printf("\nNão tem ha nenhum cliente cadastrado.");
    }
    p = iniciop;
    while (p != NULL)
    {
        if (p->code == busca)
        {
            printf("\nProduto encontrado!");
            printf("\nCodigo do produto: %d", p->code);
            printf("\nQuantidade: %d", p->qntd);
            printf("\nPreco: %f", p->preco);
            printf("\nDescricao: %s\n", p->descri);
            flag = 1;
        }
        p = p->proximo;
    }
    /*while (p != NULL)
        ;*/
    if (flag == 0)
    {
        printf("\nProduto nao encontrado!!!!");
        printf("\nRevise os dados.");
    }
}

int verificaCODE(produto *iniciop, int busca)
{

    produto *p;
    int flag = 0, newcode;
    if (iniciop == NULL)
    {
        return busca;
    }
    p = iniciop;
    while (p != NULL)
    {
        if (p->code == busca)
        {
            printf("\nCodigo de produto ja cadastrado!!");
            printf("\nDigite outro codigo: ");
            scanf("%d", &newcode);
            flag = 1;
            return verificaCODE(iniciop, newcode);
        }
        p = p->proximo;
    }
    /*while (p != NULL)
        ;*/
    if (flag == 0)
    {
        return busca;
    }
}

void removeProduto(produto **iniciop, int code, venda *iniciov)
{
    int flag = 0;
    produto *p = *iniciop;
    venda *p2 = iniciov;
    if (*iniciop == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    else
    {
        while (p != NULL)
        {
            if (p->code == code)
            {
                while (p2)
                {
                    if (p2->codigo_produto == p->code)
                    {
                        printf("\nImpossivel remover o produto!");
                        printf("\nProduto ja esta cadastrado em uma venda");
                        return;
                    }
                    p2 = p2->proximo;
                }

                printf("\nProduto encontrado!");
                printf("\nCodigo do produto: %d", p->code);
                printf("\nPreco do produto: %f", p->preco);
                printf("\nQuantidade do produto: %d", p->qntd);
                printf("\nDescricao do produto: %s", p->descri);
                printf("\nRemovendo produto!");

                if (p == *iniciop) // Se o nó a ser removido for o primeiro da lista
                {
                    *iniciop = p->proximo;
                    if (*iniciop != NULL)
                        (*iniciop)->anterior = NULL;
                }
                else // Se o nó a ser removido não for o primeiro da lista
                {
                    p->anterior->proximo = p->proximo;
                    if (p->proximo != NULL)
                        p->proximo->anterior = p->anterior;
                }

                free(p);
                flag = 1;
                break; // Não é necessário continuar percorrendo a lista
            }
            p = p->proximo;
        }

        if (flag == 0)
        {
            printf("\nCliente nao encontrado!!!!");
            printf("\nRevise os dados.");
        }
    }
}

void alteraProduto(produto **iniciop, int busca)
{
    if (*iniciop == NULL)
    {
        printf("\nNão há nenhum cliente cadastrado.\n");
        return;
    }

    produto *p = *iniciop, *aux;
    int o, space;

    while (p)
    {
        if (p->code == busca)
        {
            printf("\nProduto encontrado!");
            printf("\nCodigo do produto: %d", p->code);
            printf("\nValor do produto: %f", p->preco);
            printf("\nQuantidade do produto: %d", p->qntd);
            printf("\nDescricao do produto: %s", p->descri);
            printf("\nDeseja alterar:");
            printf("\n 1 - Alterar preco");
            printf("\n 2 - Alterar a quantidade");
            printf("\n 3 - Alterar a descricao");
            printf("\nOpção: ");
            scanf("%d", &o);

            switch (o)
            {
                float novo_preco;
                int nova_qntd;
                char nova_descri[30];
            case 1:

                printf("Digite o novo valor do produto:");
                scanf("%f", &novo_preco);
                p->preco = novo_preco;
                printf("\nPreco alterado com sucesso!");
                break;
            case 2:
                printf("Digite a novo quantidade do produto:");
                scanf("%d", &nova_qntd);
                p->qntd = nova_qntd;
                printf("\nPreco alterado com sucesso!");
                break;
            case 3:
                printf("Digite a nova descricao do produto: ");
                scanf(" %[^\n]", nova_descri);
                strcpy(p->descri, nova_descri);
                break;
            }
            return;
        }
        p = p->proximo;
    }
    printf("\nCliente não encontrado.\n");
}

void menu1()
{
    printf("\n====== MENU PRINCIPAL ======");
    printf("\nEscolha qual opcao deseja acesar:\n");
    printf("1 - Cliente\n");
    printf("2 - Produto\n");
    printf("3 - Venda\n");
    printf("4 - Opcoes de listagens\n");
    printf("0 - Sair");
    printf("\nOpcao: ");
}
void menuCliente()
{
    printf("\n====== MENU CLIENTE ======");
    printf("\nEscolha qual opcao deseja acesar:\n");
    printf("\n1 - Inclusão de cliente");
    printf("\n2 - Alteração de cliente");
    printf("\n3 - Consulta de cliente");
    printf("\n4 - Deletar cliente");
    printf("\n5 - Voltar para o menu principal");
    printf("\nOpcao: ");
}
void menuProduto()
{
    printf("\n====== MENU PRODUTO ======");
    printf("\nEscolha qual opcao deseja acesar:\n");
    printf("\n1 - Inclusão de produto");
    printf("\n2 - Alteração de produto");
    printf("\n3 - Consulta de produto");
    printf("\n4 - Deletar produto");
    printf("\n5 - Voltar para o menu principal");
    printf("\nOpcao: ");
}
void menuListagem()
{
    printf("\n====== MENU LISTAGEM ======");
    printf("\nEscolha qual opcao deseja acesar:\n");
    printf("\n1 - Ver todos os CLIENTES cadastrados");
    printf("\n2 - Ver todos os PRODUTOS cadastrados");
    printf("\n3 - Ver todas as VENDAS efetivadas");
    printf("\n4 - Ver quantos clientes compraram acima de um valor");
    printf("\n5 - Ver produtos com a quantidade abaixo de um valor");
    printf("\n6 - Voltar para o menu principal");
    printf("\nOpcao: ");
}
void menuVenda()
{
    printf("\n\n====== MENU VENDA ======");
    printf("\nEscolha qual opcao deseja acesar:\n");
    printf("\n1 - Inclusão de uma venda");
    printf("\n2 - Alteração de uma venda");
    printf("\n3 - Consulta de uma venda");
    printf("\n4 - Deletar uma venda");
    printf("\n5 - Voltar para o menu principal");
    printf("\nOpcao: ");
}
void incluirVenda(cliente *inicio, produto *iniciop, venda **iniciov, int cpf, int codigo)
{
    cliente *p = inicio;
    produto *p2 = iniciop;
    venda *infov;
    int opcao, und, flags = 0, cont = 1, flagCPF = 0;

    while (p)
    {
        if (p->cpf == cpf)
        {
            printf("\nCliente encontrado!");
            printf("\nBem-vindo %s!!!!", p->nome);
            printf("\nDigite o código do produto que deseja comprar: ");
            scanf("%d", &opcao);
            flagCPF = 1;

            while (p2)
            {
                if (p2->code == opcao)
                {
                    printf("\nProduto encontrado!!");
                    printf("\nDescrição do produto: %s", p2->descri);
                    printf("\nTemos [%d] unidades desse produto", p2->qntd);
                    printf("\nDeseja comprar quantas unidades?");
                    printf("\nUND: ");
                    scanf("%d", &und);

                    if (p2->qntd < und)
                    {
                        printf("\nImpossível comprar!");
                        printf("\nNão há [%d] unidades do produto disponíveis para compra.\n", und);
                    }
                    else
                    {
                        p2->qntd -= und;

                        infov = (venda *)malloc(sizeof(venda));
                        if (!infov)
                        {
                            printf("\nSem espaço na memória!");
                            return;
                        }
                        infov->codigo_produto = opcao;
                        infov->codigo_venda = codigo;
                        infov->cpf_cliente = cpf;
                        infov->quantidade_comprada = und;
                        infov->proximo = NULL;

                        if (*iniciov == NULL)
                        {
                            infov->proximo = *iniciov;
                            if (*iniciov != NULL)
                            {
                                (*iniciov)->anterior = infov;
                            }
                            *iniciov = infov;
                        }
                        else
                        {
                            venda *atual = *iniciov;
                            while (atual->proximo != NULL)
                            {
                                atual = atual->proximo;
                            }

                            infov->proximo = atual->proximo;
                            if (atual->proximo != NULL)
                            {
                                atual->proximo->anterior = infov;
                            }
                            infov->anterior = atual;
                            atual->proximo = infov;
                        }
                        printf("\nParabéns!! Produto comprado com sucesso!!\n");
                    }
                    flags = 1;
                }
                p2 = p2->proximo;
            }

            if (flags == 0)
            {
                printf("\nNão é possível comprar este produto!");
                printf("\nNão há nenhum produto cadastrado com este código.\n");
            }

            break;
        }

        p = p->proximo;
    }

    if (flagCPF == 0)
    {
        printf("\nCliente não encontrado");
        printf("\nPrimeiro é preciso fazer o cadastro do cliente.\n");
    }
}

void alteraVenda(venda **iniciov, produto **iniciop, cliente **inicio, int busca)
{
    if (*iniciov == NULL)
    {
        printf("\nNão há nenhuma venda cadastrada.\n");
        return;
    }

    venda *p = *iniciov, *aux;
    produto *p2 = *iniciop;
    cliente *p3 = *inicio;
    int o, codiguin, flagg = 0, reestoque = 0, pcomprados;
    while (p)
    {
        if (p->codigo_venda == busca)
        {
            printf("\nVenda encontrada!");
            printf("\nCodigo da venda: %d", p->codigo_venda);
            printf("\nCodigo do produto: %d", p->codigo_produto);
            printf("\nQuantidade comprada: %d", p->quantidade_comprada);
            printf("\nCpf do comprador: %d", p->cpf_cliente);
            printf("\n====== Deseja alterar ======");
            printf("\n 1 - Alterar produto comprado");
            printf("\n 2 - Alterar a quantidade comprada");
            printf("\n 3 - Alterar o cliente");
            printf("\nOpção: ");
            scanf("%d", &o);
            reestoque = p->quantidade_comprada;
            switch (o)
            {
            case 1:
                printf("\nAlterar produto comprado!!");
                printf("\nDigite o codigo do novo produto");
                printf("\nCodigo: ");
                scanf("%d", &codiguin);
                while (p2)
                {
                    if (p2->code == p->codigo_produto)
                    {
                        p2->qntd += reestoque;
                    }

                    if (p2->code == codiguin)
                    {
                        p2->qntd -= reestoque;
                        p->codigo_produto = p2->code;
                        flagg = 1;
                    }
                    p2 = p2->proximo;
                }
                if (flagg == 0)
                {
                    printf("\nImpossivel alterar o produto!!");
                    printf("\nProduto nao cadastrado.");
                }
                break;
            case 2:
                printf("\nAlterar quantidade comprada!!");
                printf("\nQuantos produtos realmente foram comprados: ");
                scanf("%d", &pcomprados);
                while (p2)
                {
                    if (p2->code == p->codigo_produto)
                    {
                        p2->qntd += reestoque;

                        if (p2->qntd > pcomprados)
                        {
                            p->quantidade_comprada = pcomprados;
                            p2->qntd -= pcomprados;
                            printf("\nAlterado com sucesso!");
                        }
                        else
                        {
                            printf("\nImpossivel comprar!!");
                            printf("\nNao temos tanto de mercadoria suficiente");
                        }
                        return;
                    }
                    p2 = p2->proximo;
                }
                break;
            case 3:
                printf("\nAlterar o cliente!!");
                printf("\nDigite o novo CPF da comprador");
                printf("\nCPF: ");
                scanf("%d", &codiguin);
                while (p3)
                {
                    if (p3->cpf == codiguin)
                    {
                        p->cpf_cliente = codiguin;
                        printf("\nAlterado com sucesso!");
                        flagg = 1;
                    }
                    p3 = p3->proximo;
                }
                if (flagg == 0)
                    printf("\nCPF nao foi encontrado");

                break;
            }
            return;
        }
        p = p->proximo;
    }
    printf("\nCliente não encontrado.\n");
}
void lista_todas_vendas(venda *iniciov)
{
    if (iniciov == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    venda *p;
    int cont = 1;
    p = iniciov;
    printf("\n====== Listagem de vendas ======");
    while (p)
    {
        printf("\n====== Venda [%d] ======", cont);
        printf("\nCPF do cliente: %d", p->cpf_cliente);
        printf("\nCodigo da venda: %d", p->codigo_venda);
        printf("\nCodigo do produto: %d", p->codigo_produto);
        printf("\nQuantidade comprada: %d", p->quantidade_comprada);
        cont++;
        p = p->proximo;
    }
    printf("\n\n");
}

void buscaVenda(venda *iniciov, int busca)
{

    venda *p;
    int flag = 0;
    if (iniciov == NULL)
    {
        printf("\nNão tem ha nenhuma venda cadastrada.");
    }
    p = iniciov;
    while (p != NULL)
    {
        if (p->codigo_venda == busca)
        {
            printf("\nCPF do cliente: %d", p->cpf_cliente);
            printf("\nCodigo da venda: %d", p->codigo_venda);
            printf("\nCodigo do produto: %d", p->codigo_produto);
            printf("\nQuantidade comprada: %d", p->quantidade_comprada);
            flag = 1;
        }
        p = p->proximo;
    }
    if (flag == 0)
    {
        printf("\nProduto nao encontrado!!!!");
        printf("\nRevise os dados.");
    }
}
void removeVenda(venda **iniciov, int code, produto *iniciop)
{
    int flag = 0, reestoque;
    venda *p = *iniciov;
    produto *p2 = iniciop;
    if (*iniciov == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    else
    {
        while (p != NULL)
        {
            if (p->codigo_venda == code)
            {

                printf("\nCPF do cliente: %d", p->cpf_cliente);
                printf("\nCodigo da venda: %d", p->codigo_venda);
                printf("\nCodigo do produto: %d", p->codigo_produto);
                printf("\nQuantidade comprada: %d", p->quantidade_comprada);
                reestoque = p->quantidade_comprada;
                printf("\nRemovendo venda!");

                while (p2)
                {

                    if (p2->code == p->codigo_produto)
                    {
                        p2->qntd += reestoque;
                    }

                    p2 = p2->proximo;
                }

                if (p == *iniciov) // Se o nó a ser removido for o primeiro da lista
                {
                    *iniciov = p->proximo;
                    if (*iniciov != NULL)
                        (*iniciov)->anterior = NULL;
                }
                else // Se o nó a ser removido não for o primeiro da lista
                {
                    p->anterior->proximo = p->proximo;
                    if (p->proximo != NULL)
                        p->proximo->anterior = p->anterior;
                }

                free(p);
                flag = 1;
                break; // Não é necessário continuar percorrendo a lista
            }
            p = p->proximo;
        }

        if (flag == 0)
        {
            printf("\nVenda nao encontrado!!!!");
            printf("\nRevise os dados.");
        }
    }
}
void lista_todos_valor(venda *iniciov, cliente *inicio, produto *iniciop, int valor)
{
    if (iniciov == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    venda *p;
    produto *p2 = iniciop;
    int cont = 1, flag = 0;
    float preco;
    p = iniciov;
    printf("\n====== Cliente que comprou acima de %d reais ======", valor);

    while (p2)
    {
        while (p)
        {
            preco = p->quantidade_comprada * p2->preco;
            if (preco > valor)
            {
                printf("\nCPF: %d Valor comprado: %f", p->cpf_cliente, preco);
                flag = 1;
            }
            p = p->proximo;
        }

        p2 = p2->proximo;
    }
    if (flag == 0)
    {
        printf("\nNao tem nenhum cliente que comprou acima de %d reais", valor);
    }
    printf("\n\n");
}
void lista_quantidade(produto *iniciop, int valor)
{
    if (iniciop == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    produto *p;
    int cont = 1, flag = 0;
    float preco;
    p = iniciop;
    printf("\n====== Produtos com quantidade menor que [%d] ======", valor);

    while (p)
    {

        if (valor > p->qntd)
        {
            printf("\n\nCodigo do produto: %d", p->code);
            printf("\nQuantidade: %d", p->qntd);
            printf("\nPreco: %.2f", p->preco);
            printf("\nDescricao: %s", p->descri);
        }
        p = p->proximo;
    }
}
