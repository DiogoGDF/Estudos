#include <stdio.h>

void incremetaAntes(int valor){
    printf("\n");
    printf("o endereço de mem é %p\n", &valor);
    printf("Antes de incremetar\n");
    printf("o valor vale %d\n", valor);

    printf("Depois de incremetartest\n");
    printf("o valor vale %d\n", ++valor);

    printf("\n");
}

void incremeta(int* valor){
    printf("\n");
    printf("o endereço de mem é %p\n", &valor);
    printf("Antes de incremetar\n");
    printf("o valor vale %d\n", (*valor));

    printf("Depois de incremetar\n");
    printf("o valor vale %d\n", ++(*valor));

    printf("\n");
}

int main(){
    int contador = 10;
    printf("o endereço de memória é %p\n", &contador);

    printf("Antes de incremetar\n");
    printf("o contador vale %d\n", contador);

    incremetaAntes(contador); 

    printf("O contador está valendo: %d\n", contador);

    incremeta(&contador); 

    printf("Depois de incremetar\n");
    printf("O contador vale %d\n", contador);

	return 0;
}
