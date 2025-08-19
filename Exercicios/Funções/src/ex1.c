#include <stdio.h>
#include <stdlib.h>

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y ){
    
    int tamanho_x = x1 - x0;
    int tamanho_y = y1 - y0;
    int ponto_x, ponto_y;

    for(int i = x0; i < tamanho_x; i++){
        if(x == i){
            return ponto_x = 1;
        }else{
            ponto_x = 0;
        }
    }
    for(int i = y0; i < tamanho_y; i++){
        if(y == i){
            return ponto_y = 1;
        }else{
            ponto_y = 0;
        }
    }

    if (ponto_x == 1 && ponto_y == 1) return 1;
    return 0;
}


int main(){
    int x0, y0, x1, y1, x, y;
    int validacao;
    printf("Digites os pontos x0 e x1: ");
    scanf("%d", &x0);
    scanf("%d", &x1);

    printf("Digite os valores de y0 e y1: ");
    scanf("%d", &y0);
    scanf("%d", &y1);

    printf("Digite os valores de x e y: ");
    scanf("%d", &x);
    scanf("%d", &y);

    validacao = dentro_ret(x0, y0, x1, y1, x, y);
    if(validacao){
        printf("esta dentro");
    }else{
        printf("nao esta dentro");
    }
}