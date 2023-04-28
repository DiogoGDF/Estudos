#include <stdio.h>

int main(){
    FILE *arq;
    int num, resultado, soma = 0;

    arq = fopen("arquivo.txt", "r");

    if(arq){
        printf("O arquivo existe\n\n");
        while (!feof(arq)){
            resultado = fscanf(arq, "%d", (&num));
            if(resultado == 1){ 
                soma = soma + num;
            }
        }
    }else{
        printf("O arquivo não existe\n");
    }
    printf("A soma dos numeros encontrados é %d\n", soma);

    fclose(arq);

	return 0;
}
