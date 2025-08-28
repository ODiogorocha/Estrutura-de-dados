#include "funcoes.h"


Lista* criar(int valor){
    Lista* novo_no = (Lista*)malloc(sizeof(Lista));

    if(novo_no == NULL){
        printf("Erro em alocar !!");
    }

    novo_no->valor = valor;
    novo_no->proximo = NULL;

    return novo_no;
}

void liberar(Lista* l){
Lista* aux;
    while(l != NULL){
        aux = l->proximo; 
        free(l);          
        l = aux;        
    }
}

Lista* insere_elemento_final(Lista* l, int valor){

    Lista* novo_no = criar(valor);
    Lista* auxiliar;

    if(l == NULL) return novo_no;

    auxiliar = l;

    while(auxiliar->proximo != NULL){
        auxiliar = auxiliar->proximo;
    }
    auxiliar->proximo = novo_no;

    return auxiliar;
}

int comprimento(Lista* l){
    int contador = 0;
    Lista* percorre = l; 

    while(percorre != NULL){
        contador = contador + 1;
        percorre = percorre->proximo;
    }

    return contador;
}

int maiores(Lista* l, int n){
    int contador = 0;
    Lista* percorre = l;

    while(l -> proximo != NULL){
        if(n < l -> valor){
            contador = contador + 1;
        }
        percorre = l->proximo;
    }

    return contador;
}

Lista* ultimos(Lista* l){

    if(l == NULL) return NULL;

    while(l->proximo != NULL){
        l = l->proximo;
    }
    return l;
}

Lista* concatenada(Lista* l1, Lista* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    Lista* concatena = l1;

    while(concatena->proximo != NULL){
        concatena = concatena->proximo;
    }

    concatena->proximo = l2;
    return concatena;
}

Lista* lst_altera(Lista* l){
    Lista* inverso = l;

    while(l->proximo != NULL){
        if(l->valor < 0){
            inverso->valor = l->valor + (2 * l->valor);
        }else{
            inverso->valor = l->valor - (2 * l->valor);
        }
        l = l->proximo;
    }

    return inverso;
}

float lst_calculaMedia(Lista* l){
    int valor;
    float media;

    while(l->proximo != NULL){
        valor = valor + l->valor;
        l = l->proximo;
    }

    media = valor / comprimento(l);

    return media;
}

Lista* lst_retira_ant(Lista* l, int v){
    if (l == NULL || l->proximo == NULL) return l; 

    Lista *ant_ant = NULL;
    Lista *ant = l;
    Lista *atual = l->proximo;
    Lista *novo_inicio = NULL;

    while (atual != NULL && atual->valor != v) {
        ant_ant = ant;
        ant = atual;
        atual = atual->proximo;
    }

    if (atual == NULL || ant_ant == NULL) return l; 

    if (ant_ant == NULL) {

        novo_inicio = l->proximo;
        free(l);
        return novo_inicio;
    } else {
        ant_ant->proximo = ant->proximo;
        free(ant);
        return l;
    }
}