#include <stdio.h>
#include <stdlib.h>
#include "ex_listas.h"

lista* cria_lista(int valor){
    lista* nova_lista = (lista*)malloc(sizeof(lista));
    nova_lista->valor = valor;
    nova_lista->proximo = NULL;

    return NULL;
}

lista* insere_lista(lista* list, int valor){
    lista* novo_no = (lista*)malloc(sizeof(lista));
    novo_no->valor = valor;
    novo_no->proximo = list;

    return novo_no;
}

void imprimir_listas(lista* list){
    lista* lista;
    lista = list;
    while(lista != NULL){
        printf("valor = %d\n", lista->valor);
        lista = lista->valor;
    }    
}

int lista_vazia(lista* list){
    return (list == NULL);
}

lista* busca_na_lista(lista* list, int valor){
    for(lista* i = list; list != NULL; i->proximo){
        if (i->valor == valor) {
            return i;
        }
    }
    return NULL;
}