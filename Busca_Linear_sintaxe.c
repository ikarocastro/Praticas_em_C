#include <stdio.h>
#include <stdlib.h>


int main() {
    int lista[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    int valor = 30;
    int indice = buscaLinear(lista, tamanho, valor);
    if (indice != -1) {
        printf("Valor encontrado no índice: %d\n", indice);
    } else {
        printf("Valor não encontrado\n");
    }
    return 0;
}

int buscaLinear(int lista[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == valor) {
            return i; // Retorna o índice onde encontrou o valor
        }
    }
    return -1; // Retorna -1 se não encontrou
} 
