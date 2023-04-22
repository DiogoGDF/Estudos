#include <stdio.h>
//vetores parte2
int main(){
    //vetores de inteiros
    int numeros[5];
    numeros[0] = 2;
    numeros[1] = 3;
    numeros[2] = 5;
    numeros[3] = 7;
    numeros[4] = 13;

    //vetores e reais
    float valores[5];
    for (int i = 0; i < 5; i++){
        valores[i] = (float)numeros[i] / (float)2;
    }
    for (int i = 4; i >= 0; i--){
        printf("%.1f\n", valores[i]);
    }
    return 0;
}
