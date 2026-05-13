// Praticando passagem de parâmetros por referência usando ponteiros em C

#include <stdio.h>

void dobrar(int *num) { //passei um parametro por referência usando um ponteiro
    *num *= 2;  //desreferenciando o ponteiro para acessar o valor original e dobrá-lo
}


int main() {
    int numero = 10; // armazenando o valor original
    dobrar(&numero); //passando o endereço de numero para a função dobrar, permitindo que ela modifique o valor original
    printf("Numero dobrado: %d\n", numero); // imprime o valor dobrado, que agora é 20
    return 0;
}