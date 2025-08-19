#include <stdio.h>
#include <stdlib.h>


int* aloca(int tamanho){
    int *vet = (int *)malloc(tamanho * sizeof(int));
        if (vet == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        return NULL; 
    }
    return vet; 
}

void inverte( int n, int *vet){
    int *aux = (int *)malloc(n * sizeof(int));
    if(aux == NULL){
        printf("ERRO EM ALOCAR");
        return 0;
    }

    for(int i = 0; i < n; i ++ ){
        aux[n - i] = vet[i];
    }
    for (int i = 0; i < n; i++)
    {
        vet[i] = aux[i];
    }
}



int main(){
    int tamanho = 5;
    int *vetor = aloca(tamanho);

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }

    inverte(tamanho, vetor);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d\n", vetor[i]);
    }
    
}