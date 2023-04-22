#include <stdio.h>

int main(){
	//declaração de uma string em C
	char nome[50];

	printf("Qual é seu nome? ");
	gets(nome);

	printf("Seu nome é %s", nome);

	return 0;
}
