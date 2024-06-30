#include <assert.h>
#include <stdio.h>
#include <string.h>

// Definição das estruturas
typedef struct {
    int codigo;
    char nome[100];
    char endereco[100];
    char telefone[20];
} cliente;

typedef struct {
    cliente cli[100];
    int totcli;
} hotel;

// Função para cadastrar um novo cliente no hotel
void cadastrarcliente(hotel *h, const char *nome, const char *endereco, const char *telefone) {
    h->cli[h->totcli].codigo = h->totcli + 1;
    snprintf(h->cli[h->totcli].nome, sizeof(h->cli[h->totcli].nome), "%s", nome);
    snprintf(h->cli[h->totcli].endereco, sizeof(h->cli[h->totcli].endereco), "%s", endereco);
    snprintf(h->cli[h->totcli].telefone, sizeof(h->cli[h->totcli].telefone), "%s", telefone);
    h->totcli++;
    printf("Cliente cadastrado com sucesso !!\n\n");
}

// Estrutura para armazenar informações sobre o caso de teste
typedef struct {
    char nome[100];
    char endereco[100];
    char telefone[20];
    int expected_codigo;
    char expected_nome[100];
    char expected_endereco[100];
    char expected_telefone[20];
    int actual_codigo;
    char actual_nome[100];
    char actual_endereco[100];
    char actual_telefone[20];
    bool passed;
} TestCase;

// Função para testar um caso específico
TestCase run_test(hotel *h, const char *nome, const char *endereco, const char *telefone, int expected_codigo, const char *expected_nome, const char *expected_endereco, const char *expected_telefone) {
    TestCase test;
    strncpy(test.nome, nome, sizeof(test.nome));
    strncpy(test.endereco, endereco, sizeof(test.endereco));
    strncpy(test.telefone, telefone, sizeof(test.telefone));
    test.expected_codigo = expected_codigo;
    strncpy(test.expected_nome, expected_nome, sizeof(test.expected_nome));
    strncpy(test.expected_endereco, expected_endereco, sizeof(test.expected_endereco));
    strncpy(test.expected_telefone, expected_telefone, sizeof(test.expected_telefone));

    cadastrarcliente(h, nome, endereco, telefone);

    test.actual_codigo = h->cli[h->totcli - 1].codigo;
    strncpy(test.actual_nome, h->cli[h->totcli - 1].nome, sizeof(test.actual_nome));
    strncpy(test.actual_endereco, h->cli[h->totcli - 1].endereco, sizeof(test.actual_endereco));
    strncpy(test.actual_telefone, h->cli[h->totcli - 1].telefone, sizeof(test.actual_telefone));

    test.passed = (test.actual_codigo == test.expected_codigo) &&
                  (strcmp(test.actual_nome, test.expected_nome) == 0) &&
                  (strcmp(test.actual_endereco, test.expected_endereco) == 0) &&
                  (strcmp(test.actual_telefone, test.expected_telefone) == 0);

    return test;
}

// Função para gerar o relatório de execução de testes
void generate_report(TestCase tests[], int num_tests) {
    FILE *file = fopen("test_report.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo de relatório.\n");
        return;
    }
    fprintf(file, "Relatório de Execução de Testes\n");
    fprintf(file, "===============================\n\n");
    for (int i = 0; i < num_tests; i++) {
        fprintf(file, "Caso de Teste %d:\n", i + 1);
        fprintf(file, "Entrada: Nome = %s, Endereço = %s, Telefone = %s\n", tests[i].nome, tests[i].endereco, tests[i].telefone);
        fprintf(file, "Saída Esperada: Código = %d, Nome = %s, Endereço = %s, Telefone = %s\n", tests[i].expected_codigo, tests[i].expected_nome, tests[i].expected_endereco, tests[i].expected_telefone);
        fprintf(file, "Saída Real: Código = %d, Nome = %s, Endereço = %s, Telefone = %s\n", tests[i].actual_codigo, tests[i].actual_nome, tests[i].actual_endereco, tests[i].actual_telefone);
        fprintf(file, "Resultado: %s\n\n", tests[i].passed ? "Passou" : "Falhou");
    }
    fclose(file);
}

// Função principal para executar os testes
int main() {
    hotel h;
    h.totcli = 0;

    // Definir casos de teste
    TestCase tests[] = {
        run_test(&h, "João Silva", "Rua A, 123", "12345-6789", 1, "João Silva", "Rua A, 123", "12345-6789"),
        run_test(&h, "Maria Oliveira", "Avenida B, 456", "98765-4321", 2, "Maria Oliveira", "Avenida B, 456", "98765-4321")
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    // Gerar o relatório de execução de testes
    generate_report(tests, num_tests);

    printf("Os testes foram executados. Verifique o arquivo 'test_report.txt' para o relatório.\n");

    return 0;
}
