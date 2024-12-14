#ifndef EX_PILHA_H
#define EX_PILHA_H

typedef struct Pilha {
    int capacidade;
    int topo;
    int *vetor;
} Pilha;

// Funções
Pilha* cria_pilha(int valor);
void insere_na_pilha(Pilha* pilha, int elemento);
void libera_pilha(Pilha* pilha);
void desempilha(Pilha* pilha);
int pilha_cheia(Pilha pilha);


#endif 
