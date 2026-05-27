#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementação da arvore
struct No{
    char valor[50];
    No* esquerda;
    No* direita;
};

// Função para criar e inicializar um novo No de arvore binaria, armazenando o valor recebido
// Criei uma função chamada 'criarNo' que recebe um valor do tipo string (char*) como parâmetro e retorna um ponteiro para um No da árvore binária. Dentro da função, aloco dinamicamente memória para um novo No usando malloc, copio o valor recebido para o campo 'valor' do No criado usando strcpy, e inicializo os ponteiros dos filhos 'esquerda' e 'direita' como NULL. Por fim, a função retorna o endereço do No criado.
struct No* criarNo(char* valor){
    // Aloca dinamicanete memória para um novo No e guarda o endereço em 'novo'
    // A viriavel 'novo' que é tambem do tipo estrutura de dados No, é um ponteiro que aponta para o endereço do No criado
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    // Copia o valor passado como parametro (string) para o campo 'valor' do No criado
    strcpy(novo->valor, valor);
    // Inicializa os ponteiros dos filhos 'esquerda' e 'direita' do No criado como NULL
    novo->esquerda = NULL;
    novo->direita = NULL;
    // Retorna o endereço do No criado
    return novo;
}

// Depois que a arvore foi contruida podemos percorre-la
// Para percorrer a arvore, existem tres tipos de percorrimento: pre-ordem, em-ordem e pos-ordem

void preOrdem(struct No* raiz){
    if(raiz != NULL){
        printf("%s ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(struct No* raiz){
    if(raiz != NULL){
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void posOrdem(struct No* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s ", raiz->valor);
    }
}

// Função para liberar a memória alocada para a arvore

void liberar(struct No* raiz){
    // Se o No atual existe
    if(raiz != NULL){
        // Libere primeiro a subárvore a esquerda
        liberar(raiz->esquerda);
        // Libere depois a subárvore a direita
        liberar(raiz->direita);
        // Por ultimo, libere o próprio No atual
        free(raiz);
    }
}

int main(){

        // Criando a arvore
        struct No* raiz = criarNo("Hall de entrada");

        // Liga "sala de estar" como filho à esquerda da raiz
        raiz->esquerda = criarNo("Sala de estar");

        // Liga o No "biblioteca" como filho à direita da raiz
        raiz->direita = criarNo("Biblioteca");

        // "Quarto" como filho à esquerda de "sala de estar"
        raiz->esquerda->esquerda = criarNo("Quarto");

        // Exibe os elementos de árvore em pré-ordem (raiz, esquerda, direita)
        printf("Percorrimento em pré-ordem: ");
        preOrdem(raiz);
        printf("\n");

        // Exibe os elementos de árvore em ordem (esquerda, raiz, direita)
        printf("Percorrimento em ordem: ");
        emOrdem(raiz);
        printf("\n");

        // Exibe os elementos de árvore em pós-ordem (esquerda, direita, raiz)
        printf("Percorrimento em pós-ordem: ");
        posOrdem(raiz);
        printf("\n");

        // Libera a memória alocada para a árvore
        liberar(raiz);

        // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}