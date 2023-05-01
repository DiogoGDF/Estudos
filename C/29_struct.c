#include <stdio.h>
#include <string.h>
//struct -> estrutura de dados

struct st_aluno{ //st para lembrar que é uma struct, mas n é obrigatório
    char matricula[10];
    char nome[100];
    char curso[50];
    int ano_nascimento;
};

int main(){
    struct st_aluno aluno1;

    printf("informe a matricula do aluno: ");
    fgets(aluno1.matricula, 10, stdin);
    
    printf("informe o nome do aluno: ");
    fgets(aluno1.nome, 100, stdin);

    printf("informe o curso do aluno: ");
    fgets(aluno1.curso, 50, stdin);


    printf("informe o ano de nascimento do aluno: ");
    scanf("%d", &aluno1.ano_nascimento);

    printf("==========dados do aluno=========\n");
    printf("Matricula: %s", aluno1.matricula);
    printf("Nome: %s", aluno1.nome);
    printf("Curso: %s", aluno1.curso);
    printf("Ano de nascimento %d\n", aluno1.ano_nascimento);

	return 0;
}
