#include <stdio.h>
#include <stdlib.h>

float* aloca(int n) {
    float *vet = (float *) malloc(n * sizeof(float));
    if (vet == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        return NULL; 
    }
    return vet; 
}

int negativos(int n, float *vet){
    int cont = 0;

    for(int i = 0; i < n; i++){
        if(vet[i] < 0){
            cont ++;
        }
    }

    return cont;
}


int main(){

    int tamanho = 5;
    float *vetor = aloca(tamanho);

    for(int i = 0; i < tamanho; i++){
        scanf("%f", &vetor[i]);
    }

    int conta = negativos(tamanho, vetor);

    printf("%d", conta);

    free(vetor);
}