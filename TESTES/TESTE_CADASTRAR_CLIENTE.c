#include <stdio.h>
#include <stdbool.h>

// Função que queremos testar
int soma(int a, int b) {
    return a + b;
}

// Estrutura para armazenar informações sobre o caso de teste
typedef struct {
    int input1;
    int input2;
    int expected_output;
    int actual_output;
    bool passed;
} TestCase;

// Função para testar um caso específico
TestCase run_test(int a, int b, int expected) {
    TestCase test;
    test.input1 = a;
    test.input2 = b;
    test.expected_output = expected;
    test.actual_output = soma(a, b);
    test.passed = (test.actual_output == test.expected_output);
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
        fprintf(file, "Entrada: (%d, %d)\n", tests[i].input1, tests[i].input2);
        fprintf(file, "Saída Esperada: %d\n", tests[i].expected_output);
        fprintf(file, "Saída Real: %d\n", tests[i].actual_output);
        fprintf(file, "Resultado: %s\n\n", tests[i].passed ? "Passou" : "Falhou");
    }
    fclose(file);
}

int main() {
    // Definir casos de teste
    TestCase tests[] = {
        run_test(1, 2, 3),
        run_test(-1, 1, 0),
        run_test(0, 0, 0),
        run_test(-5, -7, -12),
        run_test(1000, 2000, 3000)
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    // Gerar o relatório de execução de testes
    generate_report(tests, num_tests);

    printf("Os testes foram executados. Verifique o arquivo 'test_report.txt' para o relatório.\n");

    return 0;
}
