#include <stdio.h>

int main(){
    FILE *arq;
    char nome[99], *resultado;
    
    arq = fopen("arquivo.txt", "r");

    if(arq){
        while (!feof(arq)){ //feof = File End Of File
            resultado = fgets(nome, 99, arq);
            printf("Resultado: %d\n", ((int)resultado));
            if(resultado){
                printf("%s\n", nome);
            }
        }
    }else{
        printf("Não achei o arquivo\n");
    }

    fclose(arq);
    return 0;
}
