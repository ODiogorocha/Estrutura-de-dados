#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
    int dado;
    struct No* proximo;
}No;

typedef struct Fila{
    No* inicio;
    No* fim;
}Fila;

Fila* cria_fila(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = fila->fim = NULL;
    return fila;
}

void enfileirar(Fila* fila, int valor){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->dado = valor;
    novo_no->proximo = NULL;

    if(fila->fim == NULL){
        fila->inicio = fila->fim = novo_no;
        return;
    }

    fila->fim->proximo = novo_no;
    fila->fim = novo_no;
}

int desenfileirar(Fila* fila){
    if(fila->inicio == NULL){
        printf("Fila vazia:\n");
        return -1;
    }

    No* temporario = fila->inicio;
    int dado = temporario->dado;
    fila->inicio = fila->inicio->proximo;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    free(temporario);
    return dado;
}

void exibir_fila(Fila* fila){
    No* atual = fila->inicio;
    printf("Fila: ");

    while(atual != NULL){
        printf("%d", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}


int main(){
    Fila* fila = cria_fila();
    int numero;

    while(true){
        printf("digite o numero para colocar na fila ou digite -1 para sair:\n");
        scanf("%d", &numero);

        if(numero == -1){
            break;
        }
        enfileirar(fila, numero);
    }
    exibir_fila(fila);

}
