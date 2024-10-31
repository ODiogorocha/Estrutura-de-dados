#include <stdio.h>
#include <stdlib.h>

// Função para alocar memória para uma matriz de 3 dimensões
int*** aloca_matriz(int m, int n, int z) {
    int ***mat = (int***)malloc(m * sizeof(int**));
    for (int i = 0; i < m; i++) {
        mat[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            mat[i][j] = (int*)malloc(z * sizeof(int));
        }
    }
    return mat;
}

// Função para preencher a matriz com valores fornecidos pelo usuário
void preenche_matriz(int m, int n, int z, int ***mat) {
    printf("Preencha a matriz (%d x %d x %d):\n", m, n, z);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < z; k++) {
                printf("Elemento [%d][%d][%d]: ", i, j, k);
                scanf("%d", &mat[i][j][k]);
            }
        }
    }
}

// Função para imprimir a matriz
void imprime_matriz(int m, int n, int z, int ***mat) {
    printf("\nMatriz (%d x %d x %d):\n", m, n, z);
    for (int i = 0; i < m; i++) {
        printf("Camada %d:\n", i);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < z; k++) {
                printf("%d ", mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Função principal
int main() {
    int m, n, z;
    printf("Digite o número de linhas, colunas e profundidade da matriz: ");
    scanf("%d %d %d", &m, &n, &z);

    int ***mat = aloca_matriz(m, n, z);
    preenche_matriz(m, n, z, mat);
    imprime_matriz(m, n, z, mat);

    // Liberando a memória alocada
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(mat[i][j]);
        }
        free(mat[i]);
    }
    free(mat);

    return 0;
}
