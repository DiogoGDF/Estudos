#include <stdio.h>
/*do...while
A diferença é que a condição é checada no fim da execução e não antes de começar um novo loop
O professor usa a metafora do policial para explicar
O policial que primeiro atira e depois pergunta é o while
O policial que pergunta e depois atira é o do..while
*/
int main(){

	int numero, soma = 0;
	int i;

	for (i = 0; i < 9; i++) {
		printf("é us guri\n");
	}



	do{
		printf("Informe um número: ");
		fflush(stdout);
		scanf("%d", &numero);
		soma = soma + numero;

	}while (numero != 0);


	printf("A soma é %d", soma);


	return 0;
}
