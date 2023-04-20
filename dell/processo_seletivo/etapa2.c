#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//variável onde será armazenado o arquivo de texto
// 80016 -> numero de linhas
// 200 -> numero máx de caracteres por linha
char arquivo[80016][200];

//procura um ano a partir da linha passada por parâmetro
//e retorna a linha onde se encontra o ano
int procuraAno(int linha, char ano[4]){
    int cont1 = linha, encontrou = 0, cont2 = 0;
    while (cont1 < 80015 && encontrou == 0){
        cont1++;
        int i = 0, j = 0, k;
        while (cont2 < 4){
            if(arquivo[cont1][i++] == 59){ //59 na tabela ASCII é o caracter ';', que é o caracter utilizado para separar as colunas no arquivo .csv
                cont2++;
            }
        }
        for (k = 0; k < 4; k++){
            if(ano[k] == arquivo[cont1][i++])
                j++;
        }
        if(j == 4){
            encontrou = cont1; //salva qual é a linha do ano
        }
        cont2 = 0;
    }
    if (encontrou != 0){
        return cont1;
    }
    return 0;
}

int procuraUsuario(char nome[70]){
    int cont1 = 0, encontrou = 0;
    while (cont1 < 80015 && encontrou == 0){
        cont1++;
        int i = 0, j = 0, k = 0;
        while(k <= (int)strlen(nome)){
            if(nome[k++] == arquivo[cont1][i++]){
                j++;
            }
        }
        if(j == (int)strlen(nome)){
            encontrou = cont1; //salva a linha onde está o bolsista
        }
    }
    if (encontrou != 0){
        return cont1;
    }
    return 0;
}

int codificaNome(int cont1){
    //primeiro copiamos o nome para uma nova string
    char nome[70], nomeCodificado[70];
    int i = 0, cont2 =0;
    while(arquivo[cont1][cont2] != 59)
        nome[i++] = arquivo[cont1][cont2++]; //copiando o nome do bolsista no array nome
    cont2++;
    strncpy(nomeCodificado, nome, 70); //copiando o array nome em nomeCodificado

    for(i = 1; i < (int)strlen(nomeCodificado) - 1; i++){
        nomeCodificado[i] = nome[(int)strlen(nomeCodificado) - i - 1];
        nomeCodificado[(int)strlen(nomeCodificado) - i - 1] = nome[i];
    }
    for(i = 0; i < (int)strlen(nomeCodificado) - 1; i++){
        if(nomeCodificado[i] != 32 && nomeCodificado[i] != 90){ //caso não seja letra Z ou espaço em branco
            nomeCodificado[i] = nomeCodificado[i] + 1;
        }
        else if (nomeCodificado[i] != 32){ // caso não seja um espaço em branco
            nomeCodificado[i] = 65; //substituí a letra pela letra A
        }
    }
    printf(" %s\n", nomeCodificado);
    return cont2;
}

int imprimeCaracteres(int cont1, int cont2){
    while(arquivo[cont1][cont2] != 59 && arquivo[cont1][cont2] != '\0'){
        printf("%c", arquivo[cont1][cont2++]);
    }
    cont2++;
    return cont2;
}

int valorBolsa(int linha){
    int cont1 = 0, cont2 = 0, bolsa = 0;
    while(cont1 < 10){
        if(arquivo[linha][cont2++] == 59){
            cont1++;
        }
    }
    cont1 = 0;
    while(arquivo[linha][cont2] != 13){
        int num =(int)arquivo[linha][cont2++] - 48;
        cont1 = cont1 + num;
        if(arquivo[linha][cont2] != 13){
            cont1 = cont1 * 10;
        }
    }
    bolsa += cont1;

    return bolsa;
}

//primeira funcionalidade do programa
void func1(){
    char ano[4];
    printf("\n~ Consultar bolsa zero/Ano ~\n");
    printf("Digite o ano que você deseja consultar os dados do bolsista zero: ");
    scanf("%s", ano);

    int cont1, cont2 = 0;
    cont1 = procuraAno(0, ano);
    if (cont1 != 0){
        cont2 = 0;
        printf("NOME: ");
        cont2 = imprimeCaracteres(cont1, cont2);
        printf("\nCPF: ");
        cont2 = imprimeCaracteres(cont1, cont2);
        printf("\nENTIDADE DE ENSINO: ");
        cont2 = imprimeCaracteres(cont1, cont2);

        int cont3 = 0;
        while (cont3 < 6){
            if(arquivo[cont1][cont2++] == 59){
                cont3++;
            }
        }

        printf("\nVALOR DA BOLSA: ");
        while(arquivo[cont1][cont2] != 59){
            printf("%c", arquivo[cont1][cont2++]);
        }
        printf(" ");
        while(arquivo[cont1][cont2] != '\0'){
            printf("%c", arquivo[cont1][++cont2]);
        }
        printf("\n\n");

    }
    else {
        printf("Não tem ninguém cadastrado nesse ano\n");
    }
}

//segunda funcionalidade do programa
void func2(){
    printf("\n~ Codificar Nomes ~\n");
    printf("Digite o nome (ou parte do nome) da pessoa deseja buscar (apenas em letras maiúscolas e sem acentos)\n");
    char nome[70];
    fgetc(stdin); // para retirar a quebra de linha que foi coletada pelo scanf na escolha da funcionalidade
    fgets(nome, 70, stdin);
    nome[strlen(nome) - 1] = 0; //para não ter um retorno a mais o stdout
    int cont1, cont2 = 0;
    cont1 = procuraUsuario(nome);

    if (cont1 != 0){ //caso encotntre alguém com o nome inserido
        cont2 = 0;
        printf("NOME CODIFICADO: ");
        cont2 = codificaNome(cont1);
        int cont3 = 0;
        while (cont3 < 1){ //pula a categoria do CPF para ir direto a entidade de ensino
            if(arquivo[cont1][cont2++] == 59){
                cont3++;
            }
        }
        printf("ENTIDADE DE ENSINO: ");
        cont2 = imprimeCaracteres(cont1, cont2);
        cont3 = 0;
        while (cont3 < 1){
            if(arquivo[cont1][cont2++] == 59){
                cont3++;
            }
        }
        printf("\nANO: ");
        cont2 = imprimeCaracteres(cont1, cont2);

        cont3 = 0;
        while (cont3 < 4){
            if(arquivo[cont1][cont2++] == 59){
                cont3++;
            }
        }

        printf("\nVALOR DA BOLSA: ");
        while(arquivo[cont1][cont2] != 59){
            printf("%c", arquivo[cont1][cont2++]);
        }
        printf(" ");
        while(arquivo[cont1][cont2] != '\0'){
            printf("%c", arquivo[cont1][++cont2]);
        }
        printf("\n\n");

    }
    else {
        printf("Não tem ninguém cadastrado com esse nome\n");
    }

}

//terceira funcionalidade do programa
void func3(){
    char ano[4];
    int linha = 1, quant = 0, soma = 0;
    printf("\n~ Consultar média anual ~\n");
    printf("Digite o ano que você deseja consultar: ");
    scanf("%s", ano);

    linha = procuraAno(linha, ano);
    if(linha == 0)
        printf("ano não encontrado :(\n");
    else{
        while(linha != 0){ //enquanto ainda tiver bolsistas registrados nesse ano
            quant++;
            int cont1 = 0, cont2 = 0;
            while(cont1 < 10){ //encontrar o ; antes do valor da bolsa
                if(arquivo[linha][cont2++] == 59){
                    cont1++;
                }
            }
            cont1 = 0;
            while(arquivo[linha][cont2] != 13){
                int num =(int)arquivo[linha][cont2++] - 48; //na tabela ASCII o 48 é onde começa os números, então para converter char em int diminuo por 48
                cont1 = cont1 + num;
                if(arquivo[linha][cont2] != 13){ //verificando se esse é o ultimo digito da bolsa
                    cont1 = cont1 * 10; //se não for multiplica por 10 para poder somar os números formando o numero completo, por exemplo 700 + 60 + 5 -> 765
                }
            }
            soma += cont1;
            linha = procuraAno(linha, ano);
        }
        int media = soma / quant;
        printf("Media: R$ %d\n", media);
    }
}

//quarta funcionalidade do programa
void func4(){
    printf("\n~ Ranking valores de bolsa ~\n");
    //[numero linha] ; [valor bolsa]
    //de 0 a 2 -> maiores bolsas
    //de 3 a 5 -> menores bolsas
    int bolsa, alunos[6][2];
    //populando o array para poder comparar
    for(int i = 0; i < 3; i++){
        alunos[i][0] = 0;
        alunos[i][1] = 0;
    }
    for(int i = 3; i < 6; i++){
        alunos[i][0] = 0;
        alunos[i][1] = 10000000;
    }
    for(int i = 1; i < 80016; i++){
        bolsa = valorBolsa(i);
        //checando se tem uma bolsa maior do que os bolsistas checados até então
        //caso seja maior que o primeiro ou segundo, primeiro copia o primeiro anterior para segundo e o segundo anterior para terceiro, depois coloca esse bolsista como o primeiro
        if(bolsa > alunos[0][1]){
            alunos[2][0] = alunos[1][0];
            alunos[2][1] = alunos[1][1];
            alunos[1][0] = alunos[0][0];
            alunos[1][1] = alunos[0][1];
            alunos[0][0] = i;
            alunos[0][1] = bolsa;
        }else if(bolsa > alunos[1][1]){
            alunos[2][0] = alunos[1][0];
            alunos[2][1] = alunos[1][1];
            alunos[1][0] = i;
            alunos[1][1] = bolsa;
        }else if(bolsa > alunos[2][1]){
            alunos[2][0] = i;
            alunos[2][1] = bolsa;
        }

        if(bolsa < alunos[3][1]){
            alunos[5][0] = alunos[4][0];
            alunos[5][1] = alunos[4][1];
            alunos[4][0] = alunos[3][0];
            alunos[4][1] = alunos[3][1];
            alunos[3][0] = i;
            alunos[3][1] = bolsa;
        }else if(bolsa < alunos[4][1]){
            alunos[5][0] = alunos[4][0];
            alunos[5][1] = alunos[4][1];
            alunos[4][0] = i;
            alunos[4][1] = bolsa;
        }else if(bolsa < alunos[5][1]){
            alunos[5][0] = i;
            alunos[5][1] = bolsa;
        }

    }

    printf("\nAs possoas com as três maiores bolsas são:\n");
    for(int i = 0; i < 3; i++){
        printf("NOME: ");
        imprimeCaracteres(alunos[i][0], 0);
        printf(" ; BOLSA: %d\n", alunos[i][1]);
    }
    printf("\nAs possoas com as três menores rendas são:\n");
    for(int i = 3; i < 6; i++){
        printf("NOME: ");
        imprimeCaracteres(alunos[i][0], 0);
        printf(" ; BOLSA: %d\n", alunos[i][1]);
    }


}


int main(){
    FILE *arq;
    arq = fopen("br-capes-bolsistas-uab.csv", "r"); //Abre arquivo dos dados da uab para leitura

    //escolha -> variável para saber qual funcionalidade o usuário escolheu
    //cont1, cont2, c -> variáveis usadas na leitura do arquivo
    int escolha = 0, cont1 = 0, cont2 = 0;
    char c;

    printf("Bem vindo!\n\nEste programa foi desenvolvido em um sistema operacional Linux, e compilar e executar este programa em outro sistema operacional pode comprometer o funcionamento correto do programa\n\n");

    if(arq){ //verificando se o arquivo foi encontrado
        do {
            do{
                c = getc(arq); //lendo o arquivo caracter por caracter
                if(c != '\n')
                    arquivo[cont1][cont2++] = c; //armazenando no array
            } while (c != '\n' && c != EOF); //até o fim da linha ou o fim do arquivo
            cont1++;
            cont2 = 0;
        } while (cont1 != 80016); //80016 -> numero de linhas que o arquivo .csv tem
    }
    else{
        printf("Erro ao encontrar o arquivo\nGaranta que você tem o arquivo br-capes-bolsistas-uab.csv baixado no seu computador e se localiza na mesma pasta que este programa. Depois tente rodar o programa novamente.\n");
        exit(EXIT_FAILURE); //termino do programa com erro
    }
    fclose(arq); //Fechamento do arquivo

    while(escolha != 5){

        printf("\nDigite o número da funcionalidade que desejas utilizar:\n");
        printf("1 - Consultar bolsa zero/Ano\n");
        printf("2 - Codificar nomes\n");
        printf("3 - Consultar média anual\n");
        printf("4 - Ranking valores de bolsa\n");
        printf("5 - Terminar o programa\n");

        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                func1();
                break;
            case 2:
                func2();
                break;
            case 3:
                func3();
                break;
            case 4:
                func4();
                break;
            case 5:
                printf("Até mais!\n");
                break;
            default:
                printf("Valor inválido!\nTente novamente!\n\n");
        }
    }

    return 0;
}
