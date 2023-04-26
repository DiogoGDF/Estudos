#include <stdio.h>

int main(){
    int n;
    int* p;

    printf("Informe um numero\n");
    scanf("%d", &n);
    p = &n;

    printf("o número digitado foi %d\n", n);

    //teoricamente era para eu usar o %d e dar certo, mas provavelmente porque
    //eu to fanzendo pelo terminal ta dando erro
    //Nomralmente o %d imprimiria a versão numerica do ponteiro
    //e o %p imprime em formato de hexadecimal
    printf("O endereço de memória é %p\n", &n);

    printf("O endereço do ponteiro %p\n", p);

	return 0;
}
