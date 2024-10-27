#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um elemento não-nulo na matriz esparsa
typedef struct elemento {
    int linha;
    int coluna;
    int valor;
    struct elemento* prox;
} Elemento;

// Estrutura para a matriz esparsa
typedef struct {
    int linhas;
    int colunas;
    Elemento** linha_inicio;  // Array de ponteiros para o início de cada linha
} MatrizEsparsa;

// Função para criar a matriz esparsa
MatrizEsparsa* criar_matriz(int linhas, int colunas) {
    MatrizEsparsa* matriz = (MatrizEsparsa*) malloc(sizeof(MatrizEsparsa));
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->linha_inicio = (Elemento**) calloc(linhas, sizeof(Elemento*));
    return matriz;
}

// Função para inserir um valor na matriz esparsa
void inserir_valor(MatrizEsparsa* matriz, int linha, int coluna, int valor) {
    if (linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        printf("Posição inválida!\n");
        return;
    }

    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->linha = linha;
    novo->coluna = coluna;
    novo->valor = valor;
    novo->prox = NULL;

    // Inserir o elemento na posição correta da lista da linha
    Elemento** atual = &(matriz->linha_inicio[linha]);
    while (*atual && (*atual)->coluna < coluna) {
        atual = &((*atual)->prox);
    }
    novo->prox = *atual;
    *atual = novo;
}

// Função para imprimir a matriz esparsa
void imprimir_matriz(MatrizEsparsa* matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        Elemento* atual = matriz->linha_inicio[i];
        for (int j = 0; j < matriz->colunas; j++) {
            if (atual && atual->coluna == j) {
                printf("%d ", atual->valor);
                atual = atual->prox;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Função para consultar o valor de um elemento na posição dada
int consultar_elemento(MatrizEsparsa* matriz, int linha, int coluna) {
    if (linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        printf("Posição inválida!\n");
        return -1;
    }

    Elemento* atual = matriz->linha_inicio[linha];
    while (atual && atual->coluna < coluna) {
        atual = atual->prox;
    }
    if (atual && atual->coluna == coluna) {
        return atual->valor;
    }
    return 0;
}

// Função para liberar a memória da matriz esparsa
void liberar_matriz(MatrizEsparsa* matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        Elemento* atual = matriz->linha_inicio[i];
        while (atual) {
            Elemento* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(matriz->linha_inicio);
    free(matriz);
}

// Função principal
int main() {
    int linhas, colunas;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    MatrizEsparsa* matriz = criar_matriz(linhas, colunas);

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
        if (valor != 0) {
            inserir_valor(matriz, linha, coluna, valor);
        }
    }

    printf("Matriz esparsa:\n");
    imprimir_matriz(matriz);

    printf("Consultar elemento - informe a linha e coluna:\n");
    printf("Linha: ");
    scanf("%d", &linha);
    printf("Coluna: ");
    scanf("%d", &coluna);
    valor = consultar_elemento(matriz, linha, coluna);
    printf("Elemento em (%d, %d): %d\n", linha, coluna, valor);

    liberar_matriz(matriz);

    return 0;
}
