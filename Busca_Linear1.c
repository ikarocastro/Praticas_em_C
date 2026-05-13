#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No* proximo;
};

int buscaLinearLista(struct No* inicio, int valor) {
    int pos = 0;
    struct No* atual = inicio;
    while (atual != NULL) {
        if (atual->dado == valor) {
            return pos;
        }
        atual = atual->proximo;
        pos++;
    }
    return -1;
}
int main() {
    // Criar uma lista encadeada
    struct No* inicio = NULL;
    // Adicionar elementos à lista (código para criar a lista não está incluído aqui)
    
    int valor = 30;
    int indice = buscaLinearLista(inicio, valor);
    if (indice != -1) {
        printf("Valor encontrado no índice: %d\n", indice);
    } else {
        printf("Valor não encontrado\n");
    }
    return 0;
}


