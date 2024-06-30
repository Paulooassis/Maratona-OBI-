#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para armazenar datas
typedef struct
{
    int dia;
    int mes;
    int ano;
} data;

// Estrutura para armazenar clientes
typedef struct
{
    int codigo;
    char nome[50];
    char endereco[50];
    char telefone[20];
} cliente;

// Estrutura para armazenar funcionários
typedef struct
{
    int codigo;
    char nome[50];
    char telefone[20];
    char cargo[30];
    float salario;
} funcionario;

// Estrutura para armazenar estadia
typedef struct
{
    int codigo;
    int qnt_diarias;
    int codigo_cliente;
    int num_quarto;
    data data_entrada;
    data data_saida;
} estadia;

typedef struct
{
    int num_quarto;
    int qnt_hospedes;
    float valor_diaria;
    int status;
} quarto;

// Estrutura para armazenar hotel
typedef struct
{
    cliente cli[100];
    int totcli;

    funcionario fun[100];
    int totfun;

    estadia est[100];
    int totest;

    quarto qua[100];
    int totqua;
} hotel;

// Função para imprimir cliente no arquivo
void imprimirclientetxt(hotel *h)
{
    FILE *arq = fopen("clientes.txt", "w");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    fprintf(arq, "%d\n", h->totcli);

    for (int i = 0; i < h->totcli; i++)
    {
        fprintf(arq, "%d;", h->cli[i].codigo);
        fprintf(arq, "%s;", h->cli[i].nome);
        fprintf(arq, "%s;", h->cli[i].endereco);
        fprintf(arq, "%s\n", h->cli[i].telefone);
    }
    fclose(arq);
}

// Função para scanear cliente do arquivo
void scanearclientetxt(hotel *h)
{
    FILE *arq = fopen("clientes.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    fscanf(arq, "%d", &h->totcli);
    fgetc(arq);

    for (int i = 0; i < h->totcli; i++)
    {
        fscanf(arq, "%d", &h->cli[i].codigo);
        fgetc(arq);
        fscanf(arq, " %[^;]", h->cli[i].nome);
        fgetc(arq);
        fscanf(arq, " %[^;]", h->cli[i].endereco);
        fgetc(arq);
        fscanf(arq, " %[^\n]", h->cli[i].telefone);
        fgetc(arq);
    }
    fclose(arq);
}

// Função para imprimir funcionarios no arquivo
void imprimirfuncionariotxt(hotel *h)
{
    FILE *arq = fopen("funcionarios.txt", "w");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de funcionarios.\n");
        return;
    }

    fprintf(arq, "%d\n", h->totfun);

    for (int i = 0; i < h->totfun; i++)
    {
        fprintf(arq, "%d;", h->fun[i].codigo);
        fprintf(arq, "%s;", h->fun[i].nome);
        fprintf(arq, "%s;", h->fun[i].telefone);
        fprintf(arq, "%s;", h->fun[i].cargo);
        fprintf(arq, "%.2f\n", h->fun[i].salario);
    }
    fclose(arq);
}

// Função para scanear funcionários do arquivo
void scanearfuncionariotxt(hotel *h)
{
    FILE *arq = fopen("funcionarios.txt", "r");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de funcionarios.\n");
        return;
    }

    fscanf(arq, "%d", &h->totfun);
    fgetc(arq);

    for (int i = 0; i < h->totfun; i++)
    {
        fscanf(arq, "%d", &h->fun[i].codigo);
        fgetc(arq);
        fscanf(arq, " %[^;]", h->fun[i].nome);
        fgetc(arq);
        fscanf(arq, " %[^;]", h->fun[i].telefone);
        fgetc(arq);
        fscanf(arq, " %[^;]", h->fun[i].cargo);
        fgetc(arq);
        fscanf(arq, "%f", &h->fun[i].salario);
        fgetc(arq);
    }
    fclose(arq);
}

// Função para imprimir estadias no arquivo
void imprimirestadiatxt(hotel *h)
{
    FILE *arq = fopen("estadias.txt", "w");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de estadia.\n");
        return;
    }

    fprintf(arq, "%d\n", h->totest);

    for (int i = 0; i < h->totest; i++)
    {
        fprintf(arq, "%d;", h->est[i].codigo);
        fprintf(arq, "%d;", h->est[i].qnt_diarias);
        fprintf(arq, "%d;", h->est[i].codigo_cliente);
        fprintf(arq, "%d;", h->est[i].num_quarto);
        fprintf(arq, "%02d/%02d/%02d;", h->est[i].data_entrada.dia,
                h->est[i].data_entrada.mes, h->est[i].data_entrada.ano);
        fprintf(arq, "%02d/%02d/%02d\n", h->est[i].data_saida.dia,
                h->est[i].data_saida.mes, h->est[i].data_saida.ano);
    }
    fclose(arq);
}

// Função para scanear estadias do arquivo
void scanearestadiatxt(hotel *h)
{
    FILE *arq = fopen("estadias.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de estadia.\n");
        return;
    }

    fscanf(arq, "%d", &h->totest);
    fgetc(arq);

    for (int i = 0; i < h->totest; i++)
    {
        fscanf(arq, "%d", &h->est[i].codigo);
        fgetc(arq);
        fscanf(arq, "%d", &h->est[i].qnt_diarias);
        fgetc(arq);
        fscanf(arq, "%d", &h->est[i].codigo_cliente);
        fgetc(arq);
        fscanf(arq, "%d", &h->est[i].num_quarto);
        fgetc(arq);
        fscanf(arq, "%d", &h->est[i].data_entrada.dia);
        fgetc(arq);
        fscanf(arq, "%d", &h->est[i].data_entrada.mes);
        fgetc(arq);
        fscanf(arq, "%d", &h->est[i].data_entrada.ano);
        fgetc(arq);
        fscanf(arq, "%d", &h->est[i].data_saida.dia);
        fgetc(arq);
        fscanf(arq, "%d", &h->est[i].data_saida.mes);
        fgetc(arq);
        fscanf(arq, "%d", &h->est[i].data_saida.ano);
        fgetc(arq);
    }
    fclose(arq);
}

// Função para imprimir quartos no arquivo
void imprimirquartotxt(hotel *h)
{
    FILE *arq = fopen("quartos.txt", "w");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de quartos.\n");
        return;
    }

    fprintf(arq, "%d\n", h->totqua);

    for (int i = 0; i < h->totqua; i++)
    {
        fprintf(arq, "%d;", h->qua[i].num_quarto);
        fprintf(arq, "%d;", h->qua[i].qnt_hospedes);
        fprintf(arq, "%.2f;", h->qua[i].valor_diaria);
        if (h->qua[i].status == 0)
        {
            fprintf(arq, "desocupado\n");
        }
        else
        {
            fprintf(arq, "ocupado\n");
        }
    }
    fclose(arq);
}

// Função para scanear quartos do arquivo
void scanearquartos(hotel *h)
{

    FILE *arq = fopen("quartos.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de quartos.\n");
        return;
    }

    fscanf(arq, "%d", &h->totqua);
    fgetc(arq);

    char str[50][h->totqua];

    for (int i = 0; i < h->totqua; i++)
    {
        fscanf(arq, "%d", &h->qua[i].num_quarto);
        fgetc(arq);
        fscanf(arq, "%d", &h->qua[i].qnt_hospedes);
        fgetc(arq);
        fscanf(arq, "%f", &h->qua[i].valor_diaria);
        fgetc(arq);
        fscanf(arq, " %[^\n]", str[i]);
        if (strcmp(str[i], "ocupado") == 0)
        {
            h->qua[i].status = 1;
        }
        else
        {
            h->qua[i].status = 0;
        }
        fgetc(arq);
    }
    fclose(arq);
}

//Função que representa o menu do projeto
void menu(int *opcao)
{
    printf("\n\n--------------------------------------------\n");
    printf("\tHOTEL DESCANSO GARANTIDO !!\n");
    printf("--------------------------------------------\n");
    printf("\n\t\tMENU DE OPCOES !!\n\n");
    printf("1. Cadastrar um cliente\n");
    printf("2. Cadastrar um funcionario\n");
    printf("3. Cadastrar uma estadia\n");
    printf("4. Cadastrar um quarto\n");
    printf("5. Ver estadias do cliente\n");
    printf("6. Dar baixa na estadia\n");
    printf("7. Ver quartos livres\n");
    printf("8. Pesquisar informacoes\n");
    printf("9. Sair do programa\n\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", opcao);
}

//Função para cadastrar um cliente
void cadastrarcliente(hotel *h)
{
    printf("\n\tCADASTRAR CLIENTE !!\n\n");
    h->cli[h->totcli].codigo = h->totcli + 1;
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", h->cli[h->totcli].nome);
    printf("Digite o endereco do cliente: ");
    scanf(" %[^\n]", h->cli[h->totcli].endereco);
    printf("Digite o telefone do cliente: ");
    scanf(" %[^\n]", h->cli[h->totcli].telefone);
    printf("Cliente cadastrado com sucesso !!\n\n");
    h->totcli++;
}

//Função para cadastrar um funcionário
void cadastrarfuncionario(hotel *h)
{
    printf("\n\tCADASTRAR FUNCIONARIO !!\n\n");
    h->fun[h->totfun].codigo = h->totfun + 1;
    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", h->fun[h->totfun].nome);
    printf("Digite o telefone do funcionario: ");
    scanf(" %[^\n]", h->fun[h->totfun].telefone);
    printf("Digite o cargo do funcionario: ");
    scanf(" %[^\n]", h->fun[h->totfun].cargo);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &h->fun[h->totfun].salario);
    printf("Funcionario cadastrado com sucesso !!\n\n");
    h->totfun = h->totfun + 1;
}

//Função booleana para validar a data
bool validar_data(data d)
{
    if (d.mes < 1 || d.mes > 12 || d.dia < 1 || d.ano < 2024)
    {
        return false;
    }

    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // ve a quantidade de dias de cada mes

    if (d.ano % 4 == 0 && (d.ano % 100 != 0 || d.ano % 400 == 0)) //ver ano bissexto
    {
        dias_mes[1] = 29;
    }

    return d.dia <= dias_mes[d.mes - 1];
}

//Função booleana para verifica a maior data
bool data_maior(data d1, data d2)
{
    if (d2.ano > d1.ano)
        return true;
    if (d2.ano < d1.ano)
        return false;
    if (d2.mes > d1.mes)
        return true;
    if (d2.mes < d1.mes)
        return false;
    return d2.dia > d1.dia;
}

//Função para cadastrar um estadia
void cadastrarestadia(hotel *h)
{
    int qnt_hospedes, ver = 0;
    data dat;

    if (h->totcli > 0 && h->totqua > 0)
    {
        printf("\n\tCADASTRAR ESTADIA !!\n\n");

        do
        {
            printf("Digite o codigo do cliente: ");
            scanf("%d", &h->est[h->totest].codigo_cliente);
            for (int i = 0; i < h->totcli; i++)
            {
                if (h->est[h->totest].codigo_cliente == h->cli[i].codigo)
                {
                    ver = 1;
                    break;
                }
            }
        }
        while (ver != 1);

        printf("Digite a quantidade de hospedes: ");
        scanf("%d", &qnt_hospedes);

        do
        {
            printf("Digite a data de entrada (dia/mes/ano): ");
            scanf("%d/%d/%d", &dat.dia, &dat.mes, &dat.ano);
        }
        while (!validar_data(dat));

        h->est[h->totest].data_entrada = dat;

        do
        {
            printf("Digite a data de saida (dia/mes/ano): ");
            scanf("%d/%d/%d", &dat.dia, &dat.mes, &dat.ano);
        }
        while (!validar_data(dat) ||
                !data_maior(h->est[h->totest].data_entrada, dat));

        h->est[h->totest].data_saida = dat;

        h->est[h->totest].qnt_diarias = ((h->est[h->totest].data_saida.ano -
                                          h->est[h->totest].data_entrada.ano) *
                                         365 +
                                         (h->est[h->totest].data_saida.mes -
                                          h->est[h->totest].data_entrada.mes) *
                                         30 +
                                         (h->est[h->totest].data_saida.dia -
                                          h->est[h->totest].data_entrada.dia));

        bool quarto_encontrado = false;
        for (int i = 0; i < h->totqua; i++)
        {
            if (qnt_hospedes <= h->qua[i].qnt_hospedes && h->qua[i].status == 0)
            {
                h->qua[i].status = 1;
                h->est[h->totest].num_quarto = h->qua[i].num_quarto;
                quarto_encontrado = true;
                break;
            }
        }

        if (quarto_encontrado)
        {
            h->est[h->totest].codigo = h->totest + 1;
            h->totest = h->totest + 1;
            printf("Estadia cadastrada com sucesso!\n");
        }
        else
        {
            printf("Nao ha quartos disponiveis para a quantidade de hospedes.\n");
        }
    }
    else
    {
        printf("Nao possui clientes ou quartos cadastrados suficientes.\n\n");
    }
}

//Função para cadastrar um quarto
void cadastrarquarto(hotel *h)
{
    h->qua[h->totqua].num_quarto = h->totqua + 1;

    printf("Digite o numero de hospedes: ");
    scanf("%d", &h->qua[h->totqua].qnt_hospedes);

    printf("Digite o valor da diaria: ");
    scanf("%f", &h->qua[h->totqua].valor_diaria);

    h->qua[h->totqua].status = 0;
    printf("Quarto cadastrado com sucesso !!\n\n");
    h->totqua++;
}

//Função para exibir as estadias de um cliente
void exibeestadia(hotel *h)
{
    int cod, achou = 0;
    printf("\nDigite o codigo do cliente: ");
    scanf("%d", &cod);
    for (int i = 0; i < h->totest; i++)
    {
        if (cod == h->est[i].codigo_cliente)
        {
            achou = 1;
            printf("\nCodigo da estadia: %d\n", h->est[i].codigo);
            printf("Nome do cliente: %s\n", h->cli[cod - 1].nome);
            printf("Numero do quarto: %d\n", h->est[i].num_quarto);
            printf("Quantidade de diarias: %d\n", h->est[i].qnt_diarias);
            printf("Data de entrada: %02d/%02d/%02d\n", h->est[i].data_entrada.dia,
                   h->est[i].data_entrada.mes, h->est[i].data_entrada.ano);
            printf("Data de saida: %02d/%02d/%02d\n\n", h->est[i].data_saida.dia,
                   h->est[i].data_saida.mes, h->est[i].data_saida.ano);
        }
    }
    if (!achou)
        printf("\nNenhuma estadia encontrada para este cliente.\n");
}

// Dar baixa em alguma estadia ja existente
void darbaixaestadia(hotel *h)
{
    int codigo_estadia, codigo_quarto, achou = 0;
    float valor_total;

    printf("\nDigite o codigo da estadia a dar baixa: ");
    scanf("%d", &codigo_estadia);

    for (int i = 0; i < h->totest; i++)
    {
        if (codigo_estadia == h->est[i].codigo)
        {
            achou = 1;
            codigo_quarto = h->est[i].num_quarto;
            valor_total =
                h->est[i].qnt_diarias * h->qua[codigo_quarto - 1].valor_diaria;

            printf("\nCodigo da estadia: %d\n", h->est[i].codigo);
            printf("Codigo do cliente: %d\n", h->est[i].codigo_cliente);
            printf("Nome do cliente: %s\n",
                   h->cli[h->est[i].codigo_cliente - 1].nome);
            printf("Numero do quarto: %d\n", codigo_quarto);
            printf("Quantidade de diarias: %d\n", h->est[i].qnt_diarias);
            printf("Valor total: R$ %.2f\n", valor_total);
            printf("Data de entrada: %02d/%02d/%02d\n", h->est[i].data_entrada.dia,
                   h->est[i].data_entrada.mes, h->est[i].data_entrada.ano);
            printf("Data de saida: %02d/%02d/%02d\n", h->est[i].data_saida.dia,
                   h->est[i].data_saida.mes, h->est[i].data_saida.ano);

            for (int j = 0; j < h->totqua; j++)
            {
                if (codigo_quarto == h->qua[j].num_quarto)
                {
                    h->qua[j].status = 0;
                    break;
                }
            }

            for (int k = i; k < h->totest - 1; k++)
            {
                h->est[k] = h->est[k + 1];
            }
            h->totest--;
            printf("Estadia dada baixa com sucesso.\n");
            break;
        }
    }
    if (!achou)
        printf("\nNenhuma estadia encontrada com o codigo fornecido.\n");
}

// Função para mostrar quais quartos estao livres para estadia
void exibequartolivre(hotel *h)
{
    int achou = 0;
    printf("\nQuartos livres:\n\n");
    for (int i = 0; i < h->totqua; i++)
    {
        if (h->qua[i].status == 0)
        {
            achou = 1;
            printf("Numero do quarto: %d\n", h->qua[i].num_quarto);
            printf("Quantidade de hospedes: %d\n", h->qua[i].qnt_hospedes);
            printf("Valor da diaria: %.2f\n\n", h->qua[i].valor_diaria);
        }
    }
    if (achou == 0)
    {
        printf("\nNao ha quartos livres.\n");
    }
}

//Função usada para pesquisar informações de clientes e funcionários
void pesquisar(hotel *h)
{
    int op, cod, opcao;
    char str[50];
    bool achou = false;

    do
    {
        printf("\n\tREALIZAR PESQUISA !!\n\n");
        printf("\tDeseja pesquisar: \n\n");
        printf("1. Cliente\n2. Funcionario\n\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
    }
    while (opcao < 1 || opcao > 2);

    do
    {
        printf("\tDeseja pesquisar por: \n\n");
        printf("1. Nome\n2. Codigo\n\nDigite a opcao desejada: ");
        scanf("%d", &op);
    }
    while (op < 1 || op > 2);

    if (opcao == 1)
    {
        if (op == 1)
        {
            printf("Digite o nome: ");
            scanf(" %[^\n]", str);
            for (int i = 0; i < h->totcli; i++)
            {
                if (strcmp(str, h->cli[i].nome) == 0)
                {
                    achou = true;
                    printf("\nCodigo: %d\n", h->cli[i].codigo);
                    printf("Nome: %s\n", h->cli[i].nome);
                    printf("Endereco: %s\n", h->cli[i].endereco);
                    printf("Telefone: %s\n\n", h->cli[i].telefone);
                }
            }
        }
        else
        {
            printf("Digite o codigo: ");
            scanf("%d", &cod);
            for (int i = 0; i < h->totcli; i++)
            {
                if (cod == h->cli[i].codigo)
                {
                    achou = true;
                    printf("\nCodigo: %d\n", h->cli[i].codigo);
                    printf("Nome: %s\n", h->cli[i].nome);
                    printf("Endereco: %s\n", h->cli[i].endereco);
                    printf("Telefone: %s\n\n", h->cli[i].telefone);
                }
            }
        }
    }
    else
    {
        if (op == 1)
        {
            printf("Digite o nome: ");
            scanf(" %[^\n]", str);
            for (int i = 0; i < h->totfun; i++)
            {
                if (strcmp(str, h->fun[i].nome) == 0)
                {
                    achou = true;
                    printf("\nCodigo: %d\n", h->fun[i].codigo);
                    printf("Nome: %s\n", h->fun[i].nome);
                    printf("Telefone: %s\n", h->fun[i].telefone);
                    printf("Cargo: %s\n", h->fun[i].cargo);
                    printf("Salario: %.2f\n\n", h->fun[i].salario);
                }
            }
        }
        else
        {
            printf("Digite o codigo: ");
            scanf("%d", &cod);
            for (int i = 0; i < h->totfun; i++)
            {
                if (cod == h->fun[i].codigo)
                {
                    achou = true;
                    printf("\nCodigo: %d\n", h->fun[i].codigo);
                    printf("Nome: %s\n", h->fun[i].nome);
                    printf("Telefone: %s\n", h->fun[i].telefone);
                    printf("Cargo: %s\n", h->fun[i].cargo);
                    printf("Salario: %.2f\n\n", h->fun[i].salario);
                }
            }
        }
    }

    if (!achou)
    {
        printf("Nenhuma informacao encontrada.\n\n");
    }
}

//Main chamando todas as funções de scanear para ler as informações ja inseridas no arquivo
int main()
{
    hotel h;
    h.totcli = 0;
    h.totfun = 0;
    h.totest = 0;
    h.totqua = 0;

    scanearclientetxt(&h);
    scanearfuncionariotxt(&h);
    scanearestadiatxt(&h);
    scanearquartos(&h);

    int opcao= 0;

    while(opcao != 9){
         menu(&opcao);
        switch (opcao)
        {
        case 1:
            cadastrarcliente(&h);
            imprimirclientetxt(&h);
            break;
        case 2:
            cadastrarfuncionario(&h);
            imprimirfuncionariotxt(&h);
            break;
        case 3:
            cadastrarestadia(&h);
            imprimirestadiatxt(&h);
            imprimirquartotxt(&h);
            break;
        case 4:
            cadastrarquarto(&h);
            imprimirquartotxt(&h);
            break;
        case 5:
            exibeestadia(&h);
            break;
        case 6:
            darbaixaestadia(&h);
            imprimirestadiatxt(&h);
            imprimirquartotxt(&h);
            break;
        case 7:
            exibequartolivre(&h);
            break;
        case 8:
            pesquisar(&h);
            break;
        case 9:
            printf("\nSaindo do programa.\n\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}
