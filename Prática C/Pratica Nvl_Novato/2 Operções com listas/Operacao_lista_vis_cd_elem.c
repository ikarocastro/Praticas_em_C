#include <stdio.h>
#include <stdlib.h>

struct No{ // Cada argola da corrente
    int valor; // O osso guardado em cada argola
    struct No* proximo; // Ponteiro para o próximo osso na corrente
};

void listas(struct No* inicio){
    struct No* atual = inicio; // Começa na primeira argola da corrente

    while (atual != NULL) { // Enquanto não chegar ao final do quintal
        printf("%d -> ", atual->valor); //Late o valor do osso na argola atual
        atual = atual->proximo; // Vai para a próxima argola da corrente
    } 
    printf("NULL\n"); // Indica cheguei ao fim não tem mais osso na corrente
};
