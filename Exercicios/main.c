#include <stdio.h>
#include <stdlib.h>

typedef struct lista_dupla {
    int dados;
    struct lista_dupla* proximo;
    struct lista_dupla* anterior;
} no;

no* criar(int valor) {
    no* novo_no = (no*)malloc(sizeof(no));
    novo_no->dados = valor;
    novo_no->proximo = NULL;
    novo_no->anterior = NULL;
    return novo_no;
}

void inserir_inicio(no** inicio, int valor) {
    no* novo_no = criar(valor);
    novo_no->proximo = *inicio;

    if (*inicio != NULL) {
        (*inicio)->anterior = novo_no;
    }
    *inicio = novo_no;
}

void inserir_fim(no** inicio, int valor) {
    no* novo_no = criar(valor);

    if (*inicio == NULL) {
        *inicio = novo_no;
        return;
    }

    no* atual = *inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo_no;
    novo_no->anterior = atual;
}

int remover_no(no** inicio, int valor) {
    no* atual = *inicio;

    // Procura pelo nó com o valor especificado
    while (atual != NULL && atual->dados != valor) {
        atual = atual->proximo;
    }

    // Se o valor não foi encontrado
    if (atual == NULL) {
        return 0;
    }

    // Se o nó a ser removido for o primeiro
    if (atual->anterior == NULL) {
        *inicio = atual->proximo;
    } else {
        atual->anterior->proximo = atual->proximo;
    }

    // Se o nó a ser removido não for o último
    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
    return 1;
}

void imprimir_lista(no* inicio) {
    no* atual = inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->dados);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    no* lista = NULL;

    // Teste de inserção no início
    inserir_inicio(&lista, 10);
    inserir_inicio(&lista, 20);
    inserir_inicio(&lista, 30);

    // Teste de inserção no fim
    inserir_fim(&lista, 5);
    inserir_fim(&lista, 1);

    // Imprimir a lista
    imprimir_lista(lista);

    // Teste de remoção
    int valor_a_remover = 20;
    if (remover_no(&lista, valor_a_remover)) {
        printf("Elemento %d removido.\n", valor_a_remover);
    } else {
        printf("Elemento %d não encontrado.\n", valor_a_remover);
    }

    // Imprimir a lista após remoção
    imprimir_lista(lista);

    return 0;
}
