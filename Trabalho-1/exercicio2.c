#include <stdio.h>
#include <stdlib.h>

struct lista {
    int linha;          // Linha do elemento nao nulo
    int coluna;         // Coluna do elemento nao nulo
    int info;           // Valor do elemento nao nulo
    struct lista* prox; // Apontador para o próximo elemento nao nulo
};
typedef struct lista Lista;

// Estrutura para a matriz esparsa
struct esparsa {
    int linhas;         // numero de linhas da matriz
    int colunas;        // numero de colunas da matriz
    Lista* prim;        // Apontador para o primeiro nó da lista de elementos nao nulos
};
typedef struct esparsa Esparsa;

// Função para criar a matriz esparsa
Esparsa* criar_matriz_esparsa(int linhas, int colunas) {
    Esparsa* matriz = (Esparsa*)malloc(sizeof(Esparsa));
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->prim = NULL;
    return matriz;
}

// Funcao para adicionar um elemento nao nulo na matriz esparsa
void adicionar_elemento(Esparsa* matriz, int linha, int coluna, int valor) {
    if (valor == 0) return; // nao armazena valores nulos

    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->linha = linha;
    novo->coluna = coluna;
    novo->info = valor;
    novo->prox = matriz->prim;
    matriz->prim = novo;
}

// Funcao para preencher a matriz com valores nao nulos
void preencher_matriz(Esparsa* matriz) {
    int linha, coluna, valor;
    printf("Digite os elementos nao nulos (linha coluna valor). Digite -1 para encerrar.\n");

    while (1) {
        printf("Linha: ");
        scanf("%d", &linha);
        if (linha == -1) break;

        printf("Coluna: ");
        scanf("%d", &coluna);
        printf("Valor: ");
        scanf("%d", &valor);

        if (linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas) {
            adicionar_elemento(matriz, linha, coluna, valor);
        } else {
            printf("posicao inválida!\n");
        }
    }
}

// Funcao para imprimir a matriz esparsa completa
void imprimir_matriz(Esparsa* matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            int encontrado = 0;
            for (Lista* atual = matriz->prim; atual != NULL; atual = atual->prox) {
                if (atual->linha == i && atual->coluna == j) {
                    printf("%d ", atual->info);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) printf("0 ");
        }
        printf("\n");
    }
}

// Funcao para consultar um elemento específico na matriz
int consultar_elemento(Esparsa* matriz, int linha, int coluna) {
    for (Lista* atual = matriz->prim; atual != NULL; atual = atual->prox) {
        if (atual->linha == linha && atual->coluna == coluna) {
            return atual->info;
        }
    }
    return 0; // Retorna 0 se o elemento for nulo
}

// Funcao para calcular o somatorio de uma linha específica
int somatorio_linha(Esparsa* matriz, int linha) {
    int soma = 0;
    for (Lista* atual = matriz->prim; atual != NULL; atual = atual->prox) {
        if (atual->linha == linha) {
            soma += atual->info;
        }
    }
    return soma;
}

// Funcao para calcular o percentual de elementos nao nulos
float percentual_nao_nulos(Esparsa* matriz) {
    int total = matriz->linhas * matriz->colunas;
    int nao_nulos = 0;
    for (Lista* atual = matriz->prim; atual != NULL; atual = atual->prox) {
        nao_nulos++;
    }
    return (nao_nulos * 100.0) / total;
}

// Funcao principal
int main() {
    int linhas, colunas;
    printf("Digite o numero de linhas e colunas da matriz esparsa: ");
    scanf("%d %d", &linhas, &colunas);

    Esparsa* matriz = criar_matriz_esparsa(linhas, colunas);
    preencher_matriz(matriz);

    printf("\nMatriz completa:\n");
    imprimir_matriz(matriz);

    int linha, coluna;
    printf("\nDigite a linha e a coluna do elemento a consultar: ");
    scanf("%d %d", &linha, &coluna);
    int elemento = consultar_elemento(matriz, linha, coluna);
    printf("Elemento na posicao [%d][%d]: %d\n", linha, coluna, elemento);

    printf("\nDigite a linha para calcular o somatorio: ");
    scanf("%d", &linha);
    int soma = somatorio_linha(matriz, linha);
    printf("somatorio da linha %d: %d\n", linha, soma);

    float percentual = percentual_nao_nulos(matriz);
    printf("\nPercentual de elementos nao nulos: %.2f%%\n", percentual);

    // Libera a memória alocada
    Lista* atual = matriz->prim;
    while (atual != NULL) {
        Lista* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(matriz);

    return 0;
}
