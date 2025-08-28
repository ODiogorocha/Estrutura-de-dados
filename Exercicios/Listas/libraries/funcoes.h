#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int valor;
    struct Lista* proximo;
} Lista;


Lista* insere_elemento_final(Lista* l, int valor); // seria a lst_insere(Lista* l, int i)
Lista* concatenada(Lista* l1, Lista* l2);
Lista* lst_retira_ant(Lista* l, int v);
Lista* lst_altera(Lista* l);
Lista* ultimos(Lista* l);
Lista* criar(int valor);


float lst_calculaMedia(Lista* l);

void imprimir(Lista* l);
void liberar(Lista* l);

int maiores(Lista* l, int n);
int comprimento (Lista* l);

#endif 