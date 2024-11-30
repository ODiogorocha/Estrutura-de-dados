#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int *elementos;
    int tamanho;
    int capacidade;
} Heap;

void inicializar_heap(Heap *heap, int capacidade);
void inserir_elemento(Heap *heap, int valor);
void remover_elemento(Heap *heap);
void imprimir_heap(Heap *heap);
void liberar_heap(Heap *heap);

#endif