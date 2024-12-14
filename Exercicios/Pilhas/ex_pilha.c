#include <stdio.h>
#include <stdlib.h>
#include "ex_pilha.h"

Pilha* cria_pilha(int valor) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha == NULL) {
        printf("Falha na alocação da estrutura Pilha!\n");
        return NULL;
    }

    pilha->topo = valor;
    pilha->vetor = (int*)malloc(valor * sizeof(int));

    if (pilha->vetor == NULL) {
        printf("Falha na alocação do vetor da Pilha!\n");
        free(pilha); 
        return NULL;
    }

    printf("Pilha criada com capacidade para %d elementos.\n", valor);
    return pilha;
}

int pilha_cheia(Pilha* pilha) {
    return pilha->topo = pilha->capacidade - 1;
}

void insere_na_pilha(Pilha* pilha, int elemento) {
    if(pilha_cheia(pilha)) {
        printf("Erro: Pilha cheia. Não é possível empilhar o elemento %.2f\n", elemento);
        return 0;
    }

    pilha->topo++;
    pilha->vetor[pilha->topo] = elemento;

    return 1;
}

void libera_pilha(Pilha* pilha){
    if (pilha != NULL) {
        free(pilha->vetor);
        free(pilha);
    }
}

void desempilha(Pilha* pilha) {
    int elemento = pilha->vetor[pilha->topo];
    pilha->topo--;
    printf("Elemento %.2f desempilhado com sucesso.\n", elemento);
}
