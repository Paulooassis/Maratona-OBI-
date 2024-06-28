#include <assert.h>
#include <stdio.h>

// Definição das estruturas
typedef struct {
    int num_quarto;
    int qnt_hospedes;
    float valor_diaria;
    int status;
} quarto;

typedef struct {
    quarto qua[100];
    int totqua;
} hotel;

// Função para cadastrar um novo quarto no hotel
void cadastrarquarto(hotel *h, int qnt_hospedes, float valor_diaria) {
    h->qua[h->totqua].num_quarto = h->totqua + 1;
    h->qua[h->totqua].qnt_hospedes = qnt_hospedes;
    h->qua[h->totqua].valor_diaria = valor_diaria;
    h->qua[h->totqua].status = 0;
    h->totqua++;
    printf("Quarto cadastrado com sucesso !!\n\n");
}

// Função de teste para cadastrarquarto
void test_cadastrarquarto() {
    hotel h;
    h.totqua = 0;

    // Chamando a função para cadastrar quarto com parâmetros simulados
    cadastrarquarto(&h, 4, 120.50);

    // Verificação dos dados cadastrados
    assert(h.totqua == 1);
    assert(h.qua[0].num_quarto == 1);
    assert(h.qua[0].qnt_hospedes == 4);
    assert(h.qua[0].valor_diaria == 120.50);
    assert(h.qua[0].status == 0);

    printf("Teste de cadastrarquarto passou!\n");
}

int main() {
    // Chamada da função de teste
    test_cadastrarquarto();

    return 0;
}
