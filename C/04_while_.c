#include <stdio.h>
//while
/*
Faça um programa no qual receba e some numeros inteiros até que o número de entrada seja 0
Então apresente a soma no final.
*/
int main(){
	//váriaveis
	int numero, soma = 0;
	printf("Informe um número: ");
	fflush(stdout);
	scanf("%d", &numero);
	//entrada
	while (numero != 0){
		soma = soma + numero;
		printf("Informe um número: ");
		fflush(stdout);
		scanf("%d", &numero);
	}

	//saída
	printf("A soma é %d", soma);

	return 0;
}
