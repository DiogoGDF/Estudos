#include <stdio.h>
//tipos alfanumericos:
//	- Characters;
//	- Strings; *
//* Na linguagem C não existem Strings reais, eles são arrays de chars

int main(){
	char opcao;
	printf("informe uma opção: \n");
	printf("a - Saldo da conta\n");
	printf("b - Extrato da conta\n");
	printf("c - Limite da conta\n");
	scanf("%c", &opcao); //para receber ou imprimir char -> %c

	if (opcao == 'a'){
		printf("Saldo da conta é...\n");
	}else if(opcao == 'b'){
		printf("Extrato da conta é...\n");
	}else if(opcao == 'c'){
		printf("Limite da conta é...\n");
	}else{
		printf("Opção desconhecida\n");
	}

	//gerar alfabeto completo com loop (a partir da table ASCII)
	for(int i = 97; i <= 122; i++){
		printf("%c\n", i);
	}


	return 0;
}
