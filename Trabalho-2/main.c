#include <stdio.h>
#include "heap.h"

void exibir_menu() {
    printf("\nMenu de Opções:\n");
    printf("1 - Inserir elemento no heap\n");
    printf("2 - Remover elemento do heap\n");
    printf("3 - Imprimir heap\n");
    printf("4 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int capacidade, opcao, valor;

    printf("Informe a capacidade inicial do heap: ");
    scanf("%d", &capacidade);

    Heap heap;
    inicializar_heap(&heap, capacidade);

    do {
        exibir_menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir_elemento(&heap, valor);
                break;
            case 2:
                remover_elemento(&heap);
                break;
            case 3:
                printf("Estrutura do Heap:\n");
                imprimir_heap(&heap);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 4);

    liberar_heap(&heap);
    return 0;
}
