#include <stdio.h>
#include <stdlib.h>

struct diagonal {
    int ordem; // Ordem da matriz
    int* v;    // Vetor para armazenar os elementos da diagonal principal
};
typedef struct diagonal Diagonal;

// Funcao para criar uma matriz diagonal de uma dada ordem
Diagonal* criar_matriz_diagonal(int ordem) {
    Diagonal* matriz = (Diagonal*)malloc(sizeof(Diagonal));
    matriz->ordem = ordem;
    matriz->v = (int*)malloc(ordem * sizeof(int)); // Aloca o vetor para a diagonal principal
    return matriz;
}

// Funcao para preencher a matriz diagonal
void preencher_matriz_diagonal(Diagonal* matriz) {
    printf("Digite os valores da diagonal principal:\n");
    for (int i = 0; i < matriz->ordem; i++) {
        printf("Elemento [%d][%d]: ", i, i);
        scanf("%d", &matriz->v[i]);
    }
}

// Funcao para imprimir a matriz diagonal
void imprimir_matriz_diagonal(Diagonal* matriz) {
    printf("Matriz diagonal:\n");
    for (int i = 0; i < matriz->ordem; i++) {
        for (int j = 0; j < matriz->ordem; j++) {
            if (i == j) {
                printf("%d ", matriz->v[i]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Funcao para consultar um elemento específico da matriz
int consultar_elemento(Diagonal* matriz, int linha, int coluna) {
    if (linha < 0 || coluna < 0 || linha >= matriz->ordem || coluna >= matriz->ordem) {
        printf("Posição fora dos limites da matriz.\n");
        return -1; // Retorna -1 para indicar erro
    }
    return (linha == coluna) ? matriz->v[linha] : 0;
}

// Funcao principal
int main() {
    int ordem, linha, coluna;

    printf("Digite a ordem da matriz diagonal: ");
    scanf("%d", &ordem);

    Diagonal* matriz = criar_matriz_diagonal(ordem);
    preencher_matriz_diagonal(matriz);
    
    printf("\nMatriz completa:\n");
    imprimir_matriz_diagonal(matriz);

    printf("\nDigite a linha e a coluna do elemento que deseja consultar: ");
    scanf("%d %d", &linha, &coluna);
    int elemento = consultar_elemento(matriz, linha, coluna);

    if (elemento != -1) {
        printf("Elemento na posição [%d][%d]: %d\n", linha, coluna, elemento);
    }

    // Libera a memória alocada
    free(matriz->v);
    free(matriz);

    return 0;
}
