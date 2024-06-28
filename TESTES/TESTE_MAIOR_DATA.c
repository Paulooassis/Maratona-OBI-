#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

// Defini��o da estrutura de data
typedef struct {
    int dia;
    int mes;
    int ano;
} data;

// Fun��o para verificar se d2 � maior que d1
bool data_maior(data d1, data d2) {
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

// Fun��es de teste
void test_data_maior() {
    data d1 = {15, 6, 2024};
    data d2 = {16, 6, 2024}; // d2 � maior que d1
    data d3 = {14, 6, 2024}; // d3 � menor que d1
    data d4 = {15, 7, 2024}; // d4 � maior que d1
    data d5 = {15, 5, 2024}; // d5 � menor que d1
    data d6 = {15, 6, 2025}; // d6 � maior que d1
    data d7 = {15, 6, 2023}; // d7 � menor que d1

    assert(data_maior(d1, d2) == true);
    assert(data_maior(d1, d3) == false);
    assert(data_maior(d1, d4) == true);
    assert(data_maior(d1, d5) == false);
    assert(data_maior(d1, d6) == true);
    assert(data_maior(d1, d7) == false);
    assert(data_maior(d1, d1) == false); // Mesma data
}

int main() {
    printf("Iniciando os testes...\n");

    // Chamada das fun��es de teste
    test_data_maior();

    printf("Todos os testes passaram!\n");
    return 0;
}
