#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int lista[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == alvo) {
            return i;
        }
    }
    return -1; // Não encontrado
}

int main(){
    int lista[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    int alvo = 30;
    int indice = buscaLinear(lista, tamanho, alvo);
    if (indice != -1) {
        printf("Valor encontrado no índice: %d\n", indice);
    } else {
        printf("Valor não encontrado\n");
    }

    return 0;
}