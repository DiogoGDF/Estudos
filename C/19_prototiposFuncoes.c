#include <stdio.h>
//Protótipos de funcões
//(assinatura de funções)
//é tipo uma declaração da função
//sem a implementação

int soma(int num1, int num2);

int main(){
    printf("soma = %d\n", soma(10, 15));

	return 0;
}

int soma(int num1, int num2){
    return num1 + num2;
}
//Então os protótipos servem básicamente pra gente informar
//ao main que a função existe e está em algum outro lugar
//(já que programas seguem linearmente as intruções
