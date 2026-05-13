#include <stdio.h>
#include <stdlib.h>

void multiplicar_Errado(int c){
    c *= 2; // Modificando o valor de c dentro da função, mas isso não afetará o valor original de c no main
}

void multiplicar_Correto(int *c){
    *c *= 2; // Modificando o valor apontado por c, o que afetará o valor original de c no main
}


int main() {

    int a = 5;
    int *p = &a;

        printf("Valor de a: %d\n", a); // Imprime o valor de a, que é 5
        printf("Valor de p: %p\n",p); // Imprime o endereço de a, que é o valor armazenado em p
        printf("Valor apontado por p: %d\n", *p); // Imprime o valor apontado por p, que é o valor de a, ou seja, 5

        printf("==============================\n");

    int b = 10;
    int *q = &b;


    *q = 20; // Modificando o valor de b através do ponteiro q
    printf("Valor de b: %d\n", b); // Imprime o valor de b, que é 20
    printf("Valor apontado por q: %d\n", *q); // Imprime o valor apontado por q, que é 20

    printf("==============================\n");
        
    int c = 15;
    
    multiplicar_Errado(c); // Passando c por valor para a função multiplicar_Errado, o valor de c no main não será modificado
    printf("Valor de c apos multiplicar_Errado: %d\n", c); // Imprime
    
    multiplicar_Correto(&c); // Passando o endereço de c para a função multiplicar_Correto, permitindo que ela modifique o valor original de c
    printf("Valor de c apos multiplicar_Correto: %d\n", c);
    
    printf("==============================\n");

    int nums[3] = {1, 2, 3}; // Declarando um array de inteiros
    int *r = nums; // O nome do array é um ponteiro para o primeiro elemento do array
    
    printf("Valor do primeiro elemento do array: %d\n", r[0]); // Imprime o valor do primeiro elemento do array
    printf("Valor do segundo elemento do array: %d\n", r[1]); // Imprime o valor do segundo elemento do array
    printf("Valor do terceiro elemento do array: %d\n", r[2]); // Imprime o valor do terceiro elemento do array

    printf("==============================\n");

    //Alocação dinâmica de memória
    //Ponteiros são essenciais para alocar memória em tempo de execução:

      int *m = malloc(5 * sizeof(int)); // Alocando memória para um array de 5 inteiros
    
    if (m == NULL) { // Verificando se a alocação de memória foi bem-sucedida
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1; // Retorna um código de erro
    }
   
        for (int i = 0; i < 5; i++) {
            m[i] = i * 10; // Inicializando o array alocado dinamicamente
        }
   
    printf("Valores do array alocado dinamicamente:\n");
        for (int i = 0; i < 5; i++) {
        printf("%d ", m[i]); // Imprime os valores do array alocado dinamicamente
    }
    printf("\n");
    free(m); // Liberando a memória alocada dinamicamente, SEMPRE libere a memória alocada para evitar vazamentos de memória
    m = NULL; // boa prática: evita ponteiro pendente
   
    return 0;

}

