#include <stdio.h>
//escrevendo funções
//
//Estrutura das funções:
//- tipo de retorno
//- nome
//- parametros de entrada
//- implementação
//- retorno (opcional)

//retorna void, nome mensagem, parametros nenhum
void mensagem(){
    printf("Função!\n"); //implementação
}

int soma(int num1, int num2){
    return num1 + num2;
}

void proximo_char(char caracter){
    printf("O próximo char é %c\n", caracter+1);
}

int main(){
    mensagem();
    printf("soma = %d\n", soma(10, 15));
    proximo_char('C');

	return 0;
}
