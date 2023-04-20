#include <stdio.h>

/*
Faça um programa que receba e some 5 números inteiros e apresente a soma no final
*/



int main(){
	//váriaveis
	int numero, soma = 0; //número apenas foi declarado, soma foi declarado e inicializado igual a zero

	//entrada
	for(int i = 0; i < 5; i++){
		printf("Informe um número: ");
		fflush(stdout);
		scanf("%d", &numero);

	//processamento
		soma = soma + numero;
	}

	//saída
	printf("A soma é %d", soma);

	return 0;
}
