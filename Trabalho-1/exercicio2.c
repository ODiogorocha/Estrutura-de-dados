#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int linha;
    int coluna;
    int info;
    struct lista* prox;
} Lista;

typedef struct {
    int linhas;
    int colunas;
    Lista* prim;
} Esparsa;

// Função para criar a matriz esparsa
Esparsa* criar_matriz(int linhas, int colunas) {
    Esparsa* matriz = (Esparsa*) malloc(sizeof(Esparsa));
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->prim = NULL;
    return matriz;
}

// Função para inserir um valor não nulo na matriz esparsa
void inserir_valor(Esparsa* matriz, int linha, int coluna, int valor) {
    if (valor == 0) return;

    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->linha = linha;
    novo->coluna = coluna;
    novo->info = valor;
    novo->prox = matriz->prim;
    matriz->prim = novo;
}

// Função para preencher a matriz com valores não nulos
void preencher_matriz(Esparsa* matriz) {
    int linha, coluna, valor;
    printf("Digite os elementos não nulos (linha, coluna, valor). Digite -1 para finalizar:\n");
    while (1) {
        printf("Linha: ");
        scanf("%d", &linha);
        if (linha == -1) break;
        printf("Coluna: ");
        scanf("%d", &coluna);
        printf("Valor: ");
        scanf("%d", &valor);
        inserir_valor(matriz, linha, coluna, valor);
    }
}

// Função para imprimir a matriz esparsa
void imprimir_matriz(Esparsa* matriz) {
    Lista* atual = matriz->prim;
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            int valor = 0;
            while (atual != NULL) {
                if (atual->linha == i && atual->coluna == j) {
                    valor = atual->info;
                    break;
                }
                atual = atual->prox;
            }
            printf("%d ", valor);
        }
        printf("\n");
    }
}

// Função para consultar um elemento na matriz
int consultar_elemento(Esparsa* matriz, int linha, int coluna) {
    Lista* atual = matriz->prim;
    while (atual != NULL) {
        if (atual->linha == linha && atual->coluna == coluna) {
            return atual->info;
        }
        atual = atual->prox;
    }
    return 0; // Retorna 0 para elementos nulos
}

// Função para calcular o somatório de uma linha
int somatorio_linha(Esparsa* matriz, int linha) {
    int soma = 0;
    Lista* atual = matriz->prim;
    while (atual != NULL) {
        if (atual->linha == linha) {
            soma += atual->info;
        }
        atual = atual->prox;
    }
    return soma;
}

// Função para calcular o percentual de elementos não nulos
float percentual_nao_nulos(Esparsa* matriz) {
    int total_elementos = matriz->linhas * matriz->colunas;
    int nao_nulos = 0;
    Lista* atual = matriz->prim;
    while (atual != NULL) {
        nao_nulos++;
        atual = atual->prox;
    }
    return ((float)nao_nulos / total_elementos) * 100;
}

// Função para liberar a memória da matriz esparsa
void liberar_matriz(Esparsa* matriz) {
    Lista* atual = matriz->prim;
    while (atual != NULL) {
        Lista* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(matriz);
}

// Função principal
int main() {
    int linhas, colunas;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    Esparsa* matriz = criar_matriz(linhas, colunas);
    preencher_matriz(matriz);

    printf("Matriz Esparsa:\n");
    imprimir_matriz(matriz);

    int linha, coluna;
    printf("Consultar elemento - informe a linha e coluna:\n");
    printf("Linha: ");
    scanf("%d", &linha);
    printf("Coluna: ");
    scanf("%d", &coluna);
    int elemento = consultar_elemento(matriz, linha, coluna);
    printf("Elemento em (%d, %d): %d\n", linha, coluna, elemento);

    printf("Digite a linha para calcular o somatório: ");
    scanf("%d", &linha);
    int soma = somatorio_linha(matriz, linha);
    printf("Somatório da linha %d: %d\n", linha, soma);

    float percentual = percentual_nao_nulos(matriz);
    printf("Percentual de elementos não nulos: %.2f%%\n", percentual);

    liberar_matriz(matriz);

    return 0;
}
