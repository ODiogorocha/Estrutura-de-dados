#include <stdio.h>
#include <stdlib.h>

//estrutura basica de uma lista simples
typedef struct Node{
    int dados;
    struct Node* proximo;
}Node;

void inserir_no_inicio(Node** cabeca, int valor){
    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->dados = valor;
    novo_node->proximo = cabeca;
    *cabeca = novo_node;
}

void iserir_no_fim(Node** cabeca, int valor){
    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->dados = valor;
    novo_node->proximo = NULL;

    if(*cabeca == NULL){
        *cabeca = novo_node;
    }else{
        Node* temporario = *cabeca;
        while(temporario-> proximo!= NULL){
            temporario = temporario->proximo;
        }
        temporario->proximo = novo_node;
    }
}

void remover_do_inicio(Node** cabeca){
    if(*cabeca == NULL){
        return 0;
    }
    Node* temporario = *cabeca;
    *cabeca = (*cabeca)-> proximo;
    free(temporario);
}

//listas duplamente encadeadas

typedef struct Noduplo {
    int dado;
    struct Noduplo* proximo;
    struct Noduplo* anterior;
}Noduplo;

void inserir_no_inicio_duplo(Noduplo** inicio, int valor){
    Noduplo* novo_no = (Noduplo*)malloc(sizeof(Noduplo));
    novo_no->dado = valor;
    novo_no->proximo = *inicio;
    novo_no->anterior = NULL;

    if(*inicio != NULL){
        (*inicio)->anterior = novo_no;
    }
    *inicio = novo_no;
}

void inserir_no_fim_duplo(Noduplo** inicio, int valor){
    Noduplo* novo_no = (Noduplo*)malloc(sizeof(Noduplo));
    novo_no->dado = valor;
    novo_no->proximo = NULL;

    if(*inicio == NULL){
        novo_no->anterior = NULL;
        *inicio = novo_no;
    }

    Noduplo* atual = *inicio;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }

    atual->proximo = novo_no;
    atual->anterior = atual;
}

void remover_inicio_duplo(Noduplo** inicio){
    if(*inicio == NULL){
        return 0;
    }
    Noduplo* temporario = *inicio;
    *inicio = (*inicio)->proximo;
    if(*inicio != NULL){
        (*inicio)->anterior = NULL;
    }
    free(temporario);
}


int main(){

}