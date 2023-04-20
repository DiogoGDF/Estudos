#include <stdio.h>
//switch
/*
 * usamos o switch quando temos uma estrutura grande
 * de if/else/if else
 */


int main(){
	int valor;

	printf("Digite um valor de 1 a 7: ");
	fflush(stdout);
	scanf("%d", &valor);

	switch(valor){
	case 1:
		printf("Domingo\n");
		break; //se não tiver o break ele vai executar todas as opções seguintes
	case 2:
		printf("Segunda\n");
		break;
	case 3:
		printf("Terça\n");
		break;
	case 4:
		printf("Quarta\n");
		break;
	case 5:
		printf("Quinta\n");
		break;
	case 6:
		printf("Sexta\n");
		break;
	case 7:
		printf("Sábado\n");
		break;
	default:
		printf("Valor inválido!\n");
	}

	return 0;
}
