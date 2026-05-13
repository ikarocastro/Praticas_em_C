# include <stdio.h>
# include <stdlib.h>

struct No{ // Cadam argola da corrente
    int valor; // Osso guardado em cada argola
    struct No* proximo; // Ponteiro para o próximo argola
};

void imprimirLista(struct No* inicio) {
    struct No* atual = inicio; // Começa na primeira argola da corrente

    while (atual != NULL) { // Enquanto não chegar ao final do quintal
        printf("%d -> ", atual->valor); //Late o valor do osso na argola atual
        atual = atual->proximo; // Vai para a próxima argola da corrente
    } 
    printf("NULL\n"); // Indica cheguei ao fim não tem mais osso na corrente
}

// Se a corrente tiver os ossos 1, 2, 3, aparece:
// 1 -> 2 -> 3 -> NULL
// Resumindo: É uma lista ligada — cada pedacinho conhece o próximo, e o cachorro fareja do início até o fim sem pular nenhum osso!