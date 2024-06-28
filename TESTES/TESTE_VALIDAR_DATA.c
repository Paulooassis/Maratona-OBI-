#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

// Definição da estrutura de data
typedef struct {
    int dia;
    int mes;
    int ano;
} data;

// Função para validar a data
bool validar_data(data d) {
    if (d.mes < 1 || d.mes > 12 || d.dia < 1 || d.ano < 2024) {
        return false;
    }

    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.ano % 4 == 0 && (d.ano % 100 != 0 || d.ano % 400 == 0)) {
        dias_mes[1] = 29; // Ano bissexto
    }

    return d.dia <= dias_mes[d.mes - 1];
}

// Funções de teste
void test_validar_data() {
    data d1 = {29, 2, 2024};  // Ano bissexto
    data d2 = {31, 4, 2024};  // Abril tem 30 dias
    data d3 = {31, 12, 2023}; // Ano menor que 2024
    data d4 = {15, 6, 2024};  // Data válida

    assert(validar_data(d1) == true);
    assert(validar_data(d2) == false);
    assert(validar_data(d3) == false);
    assert(validar_data(d4) == true);
}

int main() {
    printf("Iniciando os testes...\n");

    // Chamada das funções de teste
    test_validar_data();

    printf("Todos os testes passaram!\n");
    return 0;
}
