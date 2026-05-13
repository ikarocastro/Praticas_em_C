#include <stdio.h>
#include <stdlib.h>

int main() {

    int * numeros = (int *) malloc(3 * sizeof(int)); // Aloca memória para 3 inteiros

    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30; 

    printf("%d\n", numeros[0]); // Retorna o valor 10, que é o primeiro elemento do array
    printf("%d\n", numeros[1]); // Retorna o valor 20, que é o segundo elemento do array
    printf("%d\n", numeros[2]); // Retorna o valor 30, que é o terceiro elemento do array
    
    numeros = (int *) realloc(numeros, 5 * sizeof(int)); // Realoca memória para 5 inteiros

    numeros[3] = 40;
    numeros[4] = 50; 
   
    printf("%d\n", numeros[3]); // Retorna o valor 40, que é o quarto elemento do array
    printf("%d\n", numeros[4]); // Retorna o valor 50, que é o quinto elemento do array
    
    free(numeros); // Libera a memória alocada

    return 0;
}

