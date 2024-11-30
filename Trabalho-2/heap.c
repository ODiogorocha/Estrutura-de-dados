#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void inicializar_heap(Heap *heap, int capacidade) {
    heap->elementos = (int *)malloc(capacidade * sizeof(int));
    if (!heap->elementos) {
        printf("Erro ao alocar memória para o heap.\n");
        exit(1);
    }
    heap->tamanho = 0;
    heap->capacidade = capacidade;
}

void trocar_elementos(int *a, int *b) {
    int temporario = *a;
    *a = *b;
    *b = temporario;
}

void subir_elemento(Heap *heap, int indice) {
    int indice_pai = (indice - 1) / 2;
    if (indice > 0 && heap->elementos[indice] > heap->elementos[indice_pai]) {
        trocar_elementos(&heap->elementos[indice], &heap->elementos[indice_pai]);
        subir_elemento(heap, indice_pai);
    }
}

void inserir_elemento(Heap *heap, int valor) {
    if (heap->tamanho == heap->capacidade) {
        printf("Heap cheio!\n");
        return;
    }
    heap->elementos[heap->tamanho] = valor;
    subir_elemento(heap, heap->tamanho);
    heap->tamanho++;
}

void descer_elemento(Heap *heap, int indice) {
    int maior = indice;
    int indice_esquerda = 2 * indice + 1;
    int indice_direita = 2 * indice + 2;

    if (indice_esquerda < heap->tamanho && heap->elementos[indice_esquerda] > heap->elementos[maior]) {
        maior = indice_esquerda;
    }
    if (indice_direita < heap->tamanho && heap->elementos[indice_direita] > heap->elementos[maior]) {
        maior = indice_direita;
    }
    if (maior != indice) {
        trocar_elementos(&heap->elementos[indice], &heap->elementos[maior]);
        descer_elemento(heap, maior);
    }
}

void remover_elemento(Heap *heap) {
    if (heap->tamanho == 0) {
        printf("Heap vazio!\n");
        return;
    }
    heap->elementos[0] = heap->elementos[heap->tamanho - 1];
    heap->tamanho--;
    descer_elemento(heap, 0);
}

void imprimir_heap(Heap *heap) {
    for (int i = 0; i < heap->tamanho; i++) {
        int indice_esquerda = 2 * i + 1;
        int indice_direita = 2 * i + 2;
        printf("Nó %d: ", heap->elementos[i]);
        if (indice_esquerda < heap->tamanho)
            printf("filho esq: %d, ", heap->elementos[indice_esquerda]);
        else
            printf("filho esq: vazio, ");
        if (indice_direita < heap->tamanho)
            printf("filho dir: %d\n", heap->elementos[indice_direita]);
        else
            printf("filho dir: vazio\n");
    }
}

void liberar_heap(Heap *heap) {
    free(heap->elementos);
    heap->tamanho = 0;
    heap->capacidade = 0;
}