#include <stdio.h>
#include <string.h>
//struct -> estrutura de dados

struct st_aluno { //st para lembrar que é uma struct, mas n é obrigatório
	char matricula[10];
	char nome[100];
	char curso[50];
	int ano_nascimento;
} alunos[5]; //outra foram de declarar a struct

int main(){
	for(int i = 0; i < 5; i++) {
		printf("informe a matricula do aluno: ");
		fgets(alunos[i].matricula, 10, stdin);

		printf("informe o nome do aluno: ");
		fgets(alunos[i].nome, 100, stdin);

		printf("informe o curso do aluno: ");
		fgets(alunos[i].curso, 50, stdin);


		printf("informe o ano de nascimento do aluno: ");
		scanf("%d", &alunos[i].ano_nascimento);
		getchar();
	}
	for(int i = 0; i < 5; i++) {

		printf("==========dados do aluno %d=========\n", (i+1));
		printf("Matricula: %s", alunos[i].matricula);
		printf("Nome: %s", alunos[i].nome);
		printf("Curso: %s", alunos[i].curso);
		printf("Ano de nascimento %d\n", alunos[i].ano_nascimento);
	}
	return 0;
}
