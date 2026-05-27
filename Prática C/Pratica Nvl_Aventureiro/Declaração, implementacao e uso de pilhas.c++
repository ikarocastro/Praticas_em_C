#include <stdio.h>
#include <stdlib.h>

#define MAX 5 //MAX: define a capacidade máxima da pilha.

typedef struct {
    char nome[30];  
    int idade;
} Pessoa;   // Pessoa: é um tipo personalizado contendo nome e idade.

typedef struct {
    Pessoa itens[MAX];
    int topo;
} Pilha;    // Pilha: contém um vetor de Pessoa e um inteiro topo, que representa o índice do último elemento inserido. Quando a pilha está vazia, o topo é -1.



// Tal procedimento prepara a pilha para uso.
// A atribuição de -1 ao topo é uma convenção que facilita a verificação de vazios e inserções futuras.

void inicializarPilha(Pilha *p){
    p->topo = -1;
}

// O valor retorna verdadeiro (1) se o topo for igual a -1.
// A verificação evitar remoções em uma pilha já vazia, o que causaria erro.

int pilhaVazia(Pilha *p){
   return p->topo == -1;
}

// O valor retorna verdadeiro (1) se o topo estiver no último índice possível do vetor.
// A verificação evita inserções que ultrapassariam o tamanho permitido da pilha.

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// Inserir (push)

// Adiciona um novo elemento no topo da pilha

void push(Pilha *p, Pessoa nova) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia. Não é possível inserir.\n");
        return;
    }
 
    p->topo++;
    p->itens[p->topo] = nova;
}

//O método verifica se a pilha está cheia.
//Em caso negativo, o método incrementa o topo e insere o novo elemento naquela posição.
//Push é uma operação rápida e eficiente, com complexidade constante (O(1)).

void pop(Pilha *p, Pessoa *removida) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia. Não é possível remover.\n");
        return;
    }

    *removida = p->itens[p->topo];
    p->topo--;
}

//O método verifica se a pilha está vazia antes de tentar remover.
//A função copia o conteúdo do topo para o ponteiro removido, e então reduz o topo.
//Isso simula bem o comportamento LIFO (Last In, First Out).

void peek(Pilha *p, Pessoa *visualizada) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia. Nada para espiar.\n");
        return;
    }

    *visualizada = p->itens[p->topo];
}

//A função é muito útil quando queremos saber quem é o último elemento inserido, mas sem o alterar.
//O método evita mudanças na estrutura da pilha, mantendo o topo inalterado.

void mostrarPilha(Pilha *p) {
    printf("Pilha (topo -> base):\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("[%s, %d]\n", p->itens[i].nome, p->itens[i].idade);
    }
    printf("\n");
}

int main() {

    Pilha p;
    inicializarPilha(&p);
 
    Pessoa a = {"Ana", 20};
    Pessoa b = {"Bruno", 35};
    Pessoa c = {"Carlos", 28};
 
    push(&p, a);
    push(&p, b);
    push(&p, c);
 
    mostrarPilha(&p);
 
    Pessoa removida;
    pop(&p, &removida);
    printf("Removida: %s, %d\n", removida.nome, removida.idade);
 
    mostrarPilha(&p);
 
    Pessoa topo;
    peek(&p, &topo);
    printf("Topo atual: %s, %d\n", topo.nome, topo.idade);
 
    return 0;
}

//A função inicializa a pilha e empilha três pessoas.
//O método remove o elemento do topo e mostra novamente a pilha.
//A função usa peek para inspecionar o novo topo sem o alterar.

