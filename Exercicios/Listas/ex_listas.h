#ifndef EX_LISTAS_H
#define EX_LISTAS_H

// Estrutura
typedef struct lista {
    int valor;
    struct lista* proximo;
} lista;

// Funções
lista* cria_lista(int valor);
lista* insere_lista(lista* lista, int valor);
lista* busca_na_lista(lista* list, int valor);
void imprimir_listas(lista* list);
int lista_vazia(lista* list);
#endif
