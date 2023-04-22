#include <stdio.h>
//matrizes parte 1
//matriz = array multidimensional
//char nome[40][12];

/* int exemplo[3][3];
 * [00][01][02]
 * [10][11][12]
 * [20][21][22]
*/
int main(){
    //matrizes e strings
    char nome[3][50];
    for(int i = 0; i < 3; i++){
        printf("Qual é o seu nome?");
        gets(nome[i]);
        //printf("%c", nome[i]);
    }
    for(int i = 0; i < 3; i++){
        printf("olá, %s\n", nome[i]);
    }

    return 0;
}
