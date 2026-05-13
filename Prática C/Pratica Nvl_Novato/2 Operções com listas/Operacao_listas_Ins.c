# include <stdio.h>
# include <stdlib.h>

struct No{
    int valor;
    struct No* proximo;
};


void inserirnoInicio(struct No** inicio, int valor) {
    //1. Criar um novo nó
    struct No* novo = (struct No*) malloc(sizeof(struct No));
   
    // verificar se a alocação de memória foi bem-sucedida
    if (novo == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo nó.\n");
        return;
    }
    //2. Atribuir o valor ao novo nó

    novo -> valor =valor;

    //3. Fazer o próximo do novo nó apontar para o início atual da lista
    // O ponteiro 'inicio' é um ponteiro para um ponteiro, então *inicio é o ponteiro para o primeiro nó da lista
    novo -> proximo = *inicio;

    //4. Agora, o inicío da lista passa a ser o nosso novo nó
    *inicio = novo;
};

