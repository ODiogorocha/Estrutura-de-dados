#include <stdio.h>
#include <stdlib.h>

//estrutura passada pela professora
struct diagonal 
{ 
  int ordem; //ordem da matriz 
  int* v; //o tamanho do vetor é igual a ordem da matriz. Os elementos da diagonal principal são armazenados nesse vetor
}; 
typedef struct diagonal Diagonal; 

//Funcoes
Diagonal* cria_matriz(int ordem){
    Diagonal* matriz = (Diagonal*) malloc(sizeof(Diagonal));
    matriz->ordem = ordem;
    matriz->v = (int*) malloc(ordem * sizeof(int));
    return matriz;
}

void preencher_matriz(Diagonal* matriz){
    printf("Digite os elementos da diagonal principal:\n");
    for(int i = 0; i < matriz->ordem; i++){
        printf("Elemento [%d] [%d]:\n", i, i);
        scanf("%d", &matriz->v[i]);
    }
}

void imprimir_matriz(Diagonal* matriz){
    printf("Matriz Diagonal:\n");
    for(int i = 0; i < matriz->ordem; i++){
        for(int j = 0; j < matriz->ordem; j++){
            if(i == j){
                printf("%d", matriz->v[i]);
            }else{
                printf("0 ");
            }
        }
    }
}

int consultar_elemento(Diagonal* matriz, int linha, int coluna){
    if(linha == coluna){
        return matriz->v[linha];
    }else{
        return 0;
    }
}

int main(){
    int ordem;
    printf("Informe a ordem da matriz diagonal: ");
    scanf("%d", &ordem);
    
    Diagonal* matriz = criar_matriz(ordem);
    preencher_matriz(matriz);
    imprimir_matriz(matriz);
    
    int linha, coluna;
    printf("Consulta de elemento (informe linha e coluna): ");
    scanf("%d %d", &linha, &coluna);
    int elemento = consultar_elemento(matriz, linha, coluna);
    printf("Elemento na posição (%d, %d): %d\n", linha, coluna, elemento);
    
    free(matriz->v);
    free(matriz);
    return 0;
}