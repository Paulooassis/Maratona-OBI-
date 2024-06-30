#include <assert.h>
#include <stdio.h>

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

// Função de teste para cadastrarcliente
void test_cadastrarcliente() {
    hotel h;
    h.totcli = 0;

    // Chamando a função para cadastrar cliente com parâmetros simulados
    cadastrarcliente(&h, "João Silva", "Rua A, 123", "12345-6789");

    // Verificação dos dados cadastrados
    assert(h.totcli == 1);
    assert(h.cli[0].codigo == 1);
    assert(strcmp(h.cli[0].nome, "João Silva") == 0);
    assert(strcmp(h.cli[0].endereco, "Rua A, 123") == 0);
    assert(strcmp(h.cli[0].telefone, "12345-6789") == 0);

    printf("Teste de cadastrarcliente passou!\n");
}

int main() {
    // Chamada da função de teste
    test_cadastrarcliente();

    return 0;
}
