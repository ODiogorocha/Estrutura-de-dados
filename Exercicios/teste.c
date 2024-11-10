#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int dados;
    struct lista* proximo;
    struct lista* anterior;
}lista;

lista* cria(int valor){
    lista* novo_no = (lista*)malloc(sizeof(lista));
    if(novo_no == NULL){
        printf("erro em alocar");
    }

    novo_no->dados = valor;
    novo_no->proximo = NULL;
    novo_no->anterior = NULL;
}

void inserir_inicio(lista** inicio, int valor){
    lista* novo_no = criar(valor);
    novo_no->proximo = *inicio;
    if(*inicio != NULL){
        (*inicio)->anterior = novo_no;
    }
    *inicio = novo_no;
}

void inserir_final(lista** inicio, int valor){
    lista* novo_no = criar(valor);
    novo_no->proximo = *inicio;

    if(*inicio == NULL){
        *inicio = novo_no;
        return;
    }
    lista* atual = *inicio;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novo_no;
    novo_no->anterior= atual;
}

int main(){

}