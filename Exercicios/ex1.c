#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int dados;
    struct lista* proximo;
} lista;

// Função para adicionar um novo nó na lista
void adiciona_na_lista(lista** cabeca, int valor) {
    lista* novo_no = (lista*)malloc(sizeof(lista));
    if (novo_no == NULL) { // Verificação de alocação
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_no->dados = valor;
    novo_no->proximo = *cabeca;
    *cabeca = novo_no;
}

// Função para buscar um valor na lista
int buscar_na_lista(lista* inicio, int valor) {
    lista* atual = inicio;

    while (atual != NULL) {
        if (atual->dados == valor) {
            return 1;  // Valor encontrado
        }
        atual = atual->proximo;
    }
    return 0;  // Valor não encontrado
}

// Função para liberar a memória da lista
void libera_lista(lista* inicio) {
    lista* atual = inicio;
    while (atual != NULL) {
        lista* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int remover_elemento(lista** inicio, int valor){
    lista* atual = inicio;
    lista* anterior = NULL;

    while(atual != NULL){
        if(atual->dados == valor){
            if(anterior == NULL){
                *inicio = atual->proximo;
            }else{
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0;
}

int main() {
    lista* lista = NULL; // Inicializa a lista como vazia
    int quant = 0;
    int elemento = 0;

    printf("Quantos valores gostaria de adicionar na lista:\n");
    scanf("%d", &quant);

    for (int i = 0; i < quant; i++) {  
        printf("Digite o valor:\n");
        scanf("%d", &elemento);
        adiciona_na_lista(&lista, elemento);
    }

    printf("Qual valor procurar: \n");
    scanf("%d", &elemento);

    // Chamada da função de busca
    if (buscar_na_lista(lista, elemento)) {
        printf("Valor %d encontrado na lista.\n", elemento);
    } else {
        printf("Valor %d não encontrado na lista.\n", elemento);
    }

    // Liberar memória da lista
    libera_lista(lista);

    return 0;
}
