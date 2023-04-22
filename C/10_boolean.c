#include <stdio.h>
//Booleanos (verdadeiro/falso)
//
//não existe o tipo boolean em C
//mas a linguagem reconhece 0 como falso (false)
//e 1 como verdadeiro (true)
int main(){
	int booleano = 1;

	if(booleano){
		printf("verdadeiro\n");
	}else{
		printf("falso\n");
	}

	return 0;
}
