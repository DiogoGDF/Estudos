#include <stdio.h>

int main(){
    //matrizes de inteiros
    int numeros[2][2];
    numeros[0][0] = 1;
    numeros[0][1] = 2;
    numeros[1][0] = 3;
    numeros[1][1] = 4;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("posição[%d][%d] = %d\n", i, j, numeros[i][j]);
        }
    }
    printf("\n");

    //matrizes de reais
    float valores[3][3];
    float num;
   
    for (float i = 0; i < 3; i++){
        for (float j = 0; j < 3; j++){
            num = (i+1)*(j+4)/2;
            valores[(int)i][(int)j] = num;
        }
    } 

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("posição[%d][%d] = %.2f\n", i, j, valores[i][j]);
        }
    }
	return 0;
}
