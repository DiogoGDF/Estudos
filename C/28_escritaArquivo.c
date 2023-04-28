#include <stdio.h>

int main(){
	FILE *arq;
	char fruta[10];

	arq = fopen("frutas.txt", "a");

	if(arq) {
		//se consegui criar o arqivo
		printf("informe uma fruta, ou 0 para sair: \n");
		fgets(fruta, 10, stdin); //stdin = standard input
		while(fruta[0] != '0') {
			fputs(fruta, arq);
			printf("informe uma fruta, ou 0 para sair: \n");
			fgets(fruta, 10, stdin); //stdin = standard input
		}
	}else{
		printf("não foi possivel criar o arquivo\n");
	}

	fclose(arq);
	return 0;
}
