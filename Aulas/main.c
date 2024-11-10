int main() {
    Fila* fila = criarFila();

    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);

    exibirFila(fila);

    printf("Desenfileirando: %d\n", desenfileirar(fila));
    exibirFila(fila);

    printf("Desenfileirando: %d\n", desenfileirar(fila));
    exibirFila(fila);

    // Libera a memória no final
    free(fila);

    return 0;
}
