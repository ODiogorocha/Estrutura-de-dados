#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int linha;          // Linha do elemento
    int coluna;         // Coluna do elemento
    int valor;          // Valor do elemento que viola a identidade
    struct elemento* prox; // Apontador para o próximo elemento na lista de violação
};
typedef struct elemento Elemento;

// Estrutura da matriz identidade
struct matriz_identidade {
    int ordem;          // Ordem da matriz
    Elemento* violacoes; // Lista de elementos que violam a matriz identidade
};
typedef struct matriz_identidade MatrizIdentidade;

// Funcao para criar a matriz identidade
MatrizIdentidade* criar_matriz_identidade(int ordem) {
    MatrizIdentidade* matriz = (MatrizIdentidade*)malloc(sizeof(MatrizIdentidade));
    matriz->ordem = ordem;
    matriz->violacoes = NULL;
    return matriz;
}

// Funcao para adicionar um elemento que viola a identidade
void adicionar_violacao(MatrizIdentidade* matriz, int linha, int coluna, int valor) {
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->linha = linha;
    novo->coluna = coluna;
    novo->valor = valor;
    novo->prox = matriz->violacoes;
    matriz->violacoes = novo;
}

// Funcao para preencher a matriz e verificar a identidade
void preencher_matriz(MatrizIdentidade* matriz) {
    int valor;
    printf("Preencha a matriz (%d x %d):\n", matriz->ordem, matriz->ordem);
    for (int i = 0; i < matriz->ordem; i++) {
        for (int j = 0; j < matriz->ordem; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &valor);

            if ((i == j && valor != 1) || (i != j && valor != 0)) {
                adicionar_violacao(matriz, i, j, valor);
            }
        }
    }
}

// Funcao para imprimir a matriz identidade
void imprimir_matriz(MatrizIdentidade* matriz) {
    printf("\nMatriz preenchida:\n");
    for (int i = 0; i < matriz->ordem; i++) {
        for (int j = 0; j < matriz->ordem; j++) {
            int encontrado = 0;
            for (Elemento* atual = matriz->violacoes; atual != NULL; atual = atual->prox) {
                if (atual->linha == i && atual->coluna == j) {
                    printf("%d ", atual->valor);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("%d ", (i == j) ? 1 : 0);
            }
        }
        printf("\n");
    }
}

// Funcao para mostrar os elementos que violam a identidade
void mostrar_violacoes(MatrizIdentidade* matriz) {
    if (matriz->violacoes == NULL) {
        printf("A matriz é uma identidade.\n");
    } else {
        printf("Elementos que violam a propriedade de identidade:\n");
        for (Elemento* atual = matriz->violacoes; atual != NULL; atual = atual->prox) {
            printf("Elemento [%d][%d] = %d\n", atual->linha, atual->coluna, atual->valor);
        }
    }
}

// Funcao principal
int main() {
    int ordem;
    printf("Digite a ordem da matriz identidade: ");
    scanf("%d", &ordem);

    MatrizIdentidade* matriz = criar_matriz_identidade(ordem);
    preencher_matriz(matriz);

    printf("\nMatriz completa:\n");
    imprimir_matriz(matriz);

    printf("\n");
    mostrar_violacoes(matriz);

    // Libera a memória alocada
    Elemento* atual = matriz->violacoes;
    while (atual != NULL) {
        Elemento* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(matriz);

    return 0;
}
