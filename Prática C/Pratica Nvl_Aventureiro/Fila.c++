#include <stdio.h>
#include <stdlib.h>

#define ELEMENTOS_FILA 5

typedef struct {
    int Vetor[ELEMENTOS_FILA];
    int fim;
} Fila;

// Função para enfileirar
void enfileirar(Fila *f, int valor) {
    if (f->fim >= ELEMENTOS_FILA) {
        printf("Fila cheia!\n");
        return;
    }
    f->Vetor[f->fim] = valor;
    f->fim++;
}

// Função para mostrar a fila
void mostrarFila(Fila *f) {
    if (f->fim == 0) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Mostrar fila:\n");
    for (int i = 0; i < f->fim; i++) {
        printf("Posicao %d: %d\n", i, f->Vetor[i]);
    }
}

int main() {
    Fila f;
    f.fim = 0;

    // Adicionando 5 elementos
    enfileirar(&f, 10);
    enfileirar(&f, 15);
    enfileirar(&f, 20);
    enfileirar(&f, 25);
    enfileirar(&f, 30);

    // Mostrando os elementos
    mostrarFila(&f);

    return 0;
}