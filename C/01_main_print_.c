//Aula sobre variaveis
#include <stdio.h>

int main(){
	//declarando variaveis
	int idade;

	//declarando e inicializando uma variável no mesmo comando:
	//int idade = 20;
	printf("Qual é sua idade? ");
	fflush(stdout);
	scanf("%d", &idade);
	printf("A sua idade é: %d\n", idade);

	return 0;
}
