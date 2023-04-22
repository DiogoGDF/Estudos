#include <stdio.h>
//vetores parte 1
//vetor = array unidimensional
//char nome[40];

int main(){
    //vetores e strings
    char nome[50];
    printf("Qual é o seu nome?");
    gets(nome);
    printf("olá, %s\n", nome);
    for(int i = 0; i < 6; i++){
        printf("%c", nome[i]);
    }
    printf("\n");

    //vetores e caracteres
    char letras[26];
    int cont = 0;
    for(int i = 97; i <= 122; i++){
       letras[cont++] = i;
    }
    for (int i = 0; i < 26; i++){
        printf("%d == %c\n", letras[i], letras[i]);
    }
    //char l = 'l';
    //char n = 8;  //char pode ser tanto letra quanto numero
    return 0;
}
