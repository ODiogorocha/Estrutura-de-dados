#include <stdio.h>
#include <stdlib.h>

//fila
typedef struct NoFila{
    int dado;
    struct NoFila* proximo
}NoFila;

typedef struct Fila{
    NoFila *inicio;
    NoFila *fim;
}Fila;

//inserir na fila 
void inserir_na_fila(Fila* fila, int valor){
    NoFila* novo_no = (NoFila*)malloc(sizeof(NoFila));
    novo_no->dado = valor;
    novo_no->proximo = NULL;

    if(fila->fim == NULL){
        fila->inicio = fila->fim = novo_no;
        return 0;
    }

    fila->fim->proximo = novo_no;
    fila->fim = novo_no;
}

void remover_da_fila(Fila* fila){
    if(fila->inicio == NULL){
        return 0;
    }
    NoFila* temporario = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    free(temporario);
}

int main(){

}