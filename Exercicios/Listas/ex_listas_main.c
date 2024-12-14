#include <stdio.h>
#include <stdlib.h>
#include "ex_listas.h"

int main(){
    lista* lista;
    int retorno, elemento;

    lista = cria_lista(10);
    lista = insere_lista(lista, 23);
    lista = insere_lista(lista, 45);
    retorno = lista_vazia(lista);

    if(retorno){
        printf("lista vazia !\n");
    }

    printf("imprimindo lista:\n");
    imprimir_listas(lista);

    printf("Digite o elemento a ser procurado na lista:\n");
    scanf("%d", &elemento);

    return 0;
}