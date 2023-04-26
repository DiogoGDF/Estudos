#include <stdio.h>
//Vetores e ponteiros:
//   0   1   2   3   4
// |   |   |   |   |   | 
//

int main(){
    int valores[5];

    for (int i = 0; i < 5; i++){
        printf("Informe o %d/5 valor: ", (i+1));
        scanf("%d", &valores[i]);
    }
    printf("os valores informados foram: \n");
    for (int i = 0; i < 5; i++){
        printf("%d\n", valores[i]);
    }
    for (int i = 0; i < 5; i++){
        printf("ponteiro %d: %p\n", i, &valores[i]);
    } 
    printf("Ponteiro do array: %p\n", valores);

    //o mesmo endereço de memória é alocado para o array e o primeiro elemento
    printf("%p = %p\n", &valores[0], valores);

	return 0;
}
