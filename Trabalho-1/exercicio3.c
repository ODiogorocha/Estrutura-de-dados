#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *prox, *ant;
} Nodo;

typedef struct {
    int linhas;
    int colunas;
    Nodo* inicio;
} MatrizDensa;

// Função para criar a matriz densa
MatrizDensa* criar_matriz(int linhas, int colunas) {
    MatrizDensa* matriz = (MatrizDensa*) malloc(sizeof(MatrizDensa));
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->inicio = NULL;

    // Inicialização da lista com valores nulos (0)
    Nodo* atual = NULL;
    for (int i = 0; i < linhas * colunas; i++) {
        Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
        novo->valor = 0;
        novo->prox = NULL;
        novo->ant = atual;
        if (atual) {
            atual->prox = novo;
        } else {
            matriz->inicio = novo;
        }
        atual = novo;
    }
    return matriz;
}

// Função para inserir valor na posição especificada
void inserir_valor(MatrizDensa* matriz, int linha, int coluna, int valor) {
    if (linha >= matriz->linhas || coluna >= matriz->colunas || linha < 0 || coluna < 0) {
        printf("Posição inválida!\n");
        return;
    }

    int posicao = linha * matriz->colunas + coluna;
    Nodo* atual = matriz->inicio;

    // Navega até a posição desejada
    for (int i = 0; i < posicao; i++) {
        atual = atual->prox;
    }
    atual->valor = valor;
}

// Função para imprimir a matriz
void imprimir_matriz(MatrizDensa* matriz) {
    Nodo* atual = matriz->inicio;
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            printf("%d ", atual->valor);
            atual = atual->prox;
        }
        printf("\n");
    }
}

// Função para consultar o valor de um elemento na posição dada
int consultar_elemento(MatrizDensa* matriz, int linha, int coluna) {
    if (linha >= matriz->linhas || coluna >= matriz->colunas || linha < 0 || coluna < 0) {
        printf("Posição inválida!\n");
        return -1;
    }

    int posicao = linha * matriz->colunas + coluna;
    Nodo* atual = matriz->inicio;

    for (int i = 0; i < posicao; i++) {
        atual = atual->prox;
    }
    return atual->valor;
}

// Função para calcular o somatório de uma linha
int somatorio_linha(MatrizDensa* matriz, int linha) {
    if (linha >= matriz->linhas || linha < 0) {
        printf("Linha inválida!\n");
        return 0;
    }

    int soma = 0;
    Nodo* atual = matriz->inicio;

    // Navega até o início da linha desejada
    for (int i = 0; i < linha * matriz->colunas; i++) {
        atual = atual->prox;
    }

    // Soma os elementos da linha
    for (int j = 0; j < matriz->colunas; j++) {
        soma += atual->valor;
        atual = atual->prox;
    }

    return soma;
}

// Função para liberar a memória da matriz
void liberar_matriz(MatrizDensa* matriz) {
    Nodo* atual = matriz->inicio;
    while (atual) {
        Nodo* temp = atual;
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

    MatrizDensa* matriz = criar_matriz(linhas, colunas);

    int linha, coluna, valor;
    printf("Digite os elementos da matriz (linha, coluna, valor). Digite -1 para finalizar:\n");
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

    printf("Matriz:\n");
    imprimir_matriz(matriz);

    printf("Consultar elemento - informe a linha e coluna:\n");
    printf("Linha: ");
    scanf("%d", &linha);
    printf("Coluna: ");
    scanf("%d", &coluna);
    valor = consultar_elemento(matriz, linha, coluna);
    printf("Elemento em (%d, %d): %d\n", linha, coluna, valor);

    printf("Digite a linha para calcular o somatório: ");
    scanf("%d", &linha);
    int soma = somatorio_linha(matriz, linha);
    printf("Somatório da linha %d: %d\n", linha, soma);

    liberar_matriz(matriz);

    return 0;
}
