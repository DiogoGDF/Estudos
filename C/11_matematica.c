#include <stdio.h>
//operações matemáticas
//
//Somar +
//subtrair -
//dividir /
//elevar ao quadrado x * x
//(int)resto da divisão (módulo) %

int main(){
	int num1, num2;
	float res;
	printf("1N: ");
	scanf("%d", &num1);
	printf("2N: ");
	scanf("%d", &num2);

	//soma
	res = num1 + num2;
	printf("%d + %d = %d\n", num1, num2, (int)res);

	//subração
	res = num1 - num2;
	printf("%d - %d = %d\n", num1, num2, (int)res);

	//multiplicação
	res = num1 * num2;
	printf("%d * %d = %d\n", num1, num2, (int)res);

	//dividir
	res = (float)num1 / (float)num2;
	printf("%d / %d = %.2f\n", num1, num2, res);

	//elevar ao quadrado
	res = num1 * num1;
	printf("%d ** 2 = %d\n", num1, (int)res);

	//modulo
	res = num1 % num2;
	printf("%d %c %d = %d\n", num1, 37, num2, (int)res);

	//verificando se ambos os números passados são par ou impar)
	if(num1 % 2 == 0 && num2 % 2 == 0){
		printf("Ambos os números são par\n");
	}else if(num1 % 2 == 0 || num2 % 2 == 0){
		printf("Apenas um dos dois números é par\n");
	}else{
		printf("Ambos os números são impar\n");
	}

	return 0;
}
