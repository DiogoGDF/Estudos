#include <stdio.h>
//tipos de dados
//tipos numéricos:
//	- Inteiros
//	- Reais



int main(){
	//inteiros
	int var1 = 20; 
	//reais
	float media, nota1, nota2;
	long double var2 = 43.0392349058304958; //suporta praticamente o dobro que o double

	printf("qual a primeira nota?");
	scanf("%f", &nota1);

	printf("qual é a segunda nota?");
	scanf("%f", &nota2);
	
	media = (nota1 + nota2) / 2;
	printf("Sua média é %.2f\n", media);//.2 é a quantidade de números após a virgula que queremos
	printf("Para imprimir int: %d\n", var1);	
	printf("para imprimir long double: %Lf\n", var2);// p double normal lf
	return 0;
}
