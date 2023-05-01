#include <stdio.h>
#include <string.h>
//struct -> estrutura de dados

struct st_contato{ //st para lembrar que é uma struct, mas n é obrigatório
    char nome[100];
    char telefone[20];
    char email[100];
};

// struct com structs;
struct st_agenda{
    struct st_contato contatos[100];
}agenda;

int main(){
    for(int i = 0; i < 3; i++){
        printf("informe o nome do contato: ");
        fgets(agenda.contatos[i].nome, 100, stdin);

        printf("informe o telefone do contato: ");
        fgets(agenda.contatos[i].telefone, 20, stdin);

        printf("informe o e-mail do contato: ");
        fgets(agenda.contatos[i].email, 100, stdin);
    }   
    for(int i = 0; i < 3; i++){
        printf("==========dados do contato %d=========\n", (i+1));
        printf("Nome: %s", agenda.contatos[i].nome);
        printf("Telefone: %s", agenda.contatos[i].telefone);
        printf("email: %s\n", agenda.contatos[i].email);
    }
	return 0;
}
