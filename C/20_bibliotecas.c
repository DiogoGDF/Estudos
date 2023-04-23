#include <stdio.h>
#include "minha_bib.h"
//nessa aula estamos criando a biblioteca acima
//se cria um arquivo com o nome da biblioteca escrito acima
//no mesmo diretório que o programa C
//mas a biblioteca tem apenas protótipos de funções
//então se cira um 3 arquivo, que é .c da biblioteca onde
//dizemos o que que as funcoes fazem


int main(){
    mensagem();
    int n1, n2;

    printf("informe o primeiro numero: ");
    scanf("%d", &n1);

    printf("informe o segundo numero: ");
    scanf("%d", &n2);
    printf("a soma é %d\n", soma(n1, n2));
    printf("a multiplicação é %d\n", multiplicacao(n1, n2));  

	return 0;
}
