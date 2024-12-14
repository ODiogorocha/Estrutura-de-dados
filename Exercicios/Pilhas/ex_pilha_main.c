#include <stdio.h>
#include <stdlib.h>
#include "ex_pilha.h"

int main() {
    Pilha* pilha;
    int valor;

    printf("Digite o tamanho da pilha:\n");
    scanf("%d", &valor);

    pilha = cria_pilha(valor);
    if (pilha == NULL) {
        printf("Erro ao criar a pilha.\n");
        return 1; 
    }

    printf("Pilha criada com sucesso.\n");


    return 0;
}
