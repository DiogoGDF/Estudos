#include <stdio.h>

int main(){
    FILE *arq;
    char c;

    //fopen (nome, forma de abertura)
    //w - abrir o arquivo para escrita se o arquivo já existe sera sobreescrito
    //r - abrir o arquivo para leitura (n pode escrever)
    //a - abrir o arquivo para adição de conteúdo (append)
    arq = fopen("arquivo.txt", "r");

    if(arq){
        printf("O arquivo existe\n\n");
        while ((c = getc(arq)) != EOF){ //EOF = end of file
            printf("%c", c); //está lendo caracter por caracter
        }
    }else{
        printf("O arquivo não existe\n");
    }

    //sempre devemos fechar a manipulação do arquivo
    fclose(arq);

	return 0;
}
