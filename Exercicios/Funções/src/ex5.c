#include <stdio.h>
#include <stdlib.h>


float* aloca(int tamanho){
    float *vetor = (float *)malloc(tamanho * sizeof(float));
    if(vetor == NULL){
        printf("ERRO AO ALOCAR !!");
        return 0;
    }
    return vetor;
}

void le_vetor(int tamanho, float *vetor){
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%f", vetor[i]);
    }
}

double media(int tamanho, float *vetor){
    double soma = 0;

    for (int i = 0; i < tamanho; i++)
    {
        soma = soma + vetor[i];
    }
    return soma / tamanho;
}

double verifica_percentual(int tamanho, int media, float *vetor){
    double aux = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] > media)
        {
            aux = aux + vetor[i];
        }
    }
    return aux / 100;
}

int main(){
    int tamanho;
    float *vetor;
    double med;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tamanho);
    printf("passou \n");

    vetor = aloca(tamanho);

    printf("digite os numeros do vetor: \n");
    le_vetor(tamanho, vetor);
    med = media(tamanho, vetor);

    printf("o percentual é %f", verifica_percentual(tamanho, med, vetor));
    free(vetor);
}