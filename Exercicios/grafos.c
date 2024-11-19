#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int destino;
    struct No* proximo;
} No;

typedef struct Grafo {
    int numVertices;
    No** listaAdj;
} Grafo;

Grafo* criarGrafo(int vertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = vertices;
    grafo->listaAdj = (No**)malloc(vertices * sizeof(No*));

    for (int i = 0; i < vertices; i++) {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->destino = destino;
    novoNo->proximo = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNo;

    novoNo = (No*)malloc(sizeof(No));
    novoNo->destino = origem;
    novoNo->proximo = grafo->listaAdj[destino];
    grafo->listaAdj[destino] = novoNo;
}

void imprimirGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        No* temp = grafo->listaAdj[i];
        printf("\nLista de adjacência do vértice %d\n", i);
        while (temp) {
            printf("%d -> ", temp->destino);
            temp = temp->proximo;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices = 4;
    Grafo* grafo = criarGrafo(vertices);

    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 2, 3);

    imprimirGrafo(grafo);

    return 0;
}
