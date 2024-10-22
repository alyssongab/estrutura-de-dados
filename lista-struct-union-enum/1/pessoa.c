#include <stdio.h>
#include <string.h>

typedef struct {
    char rua[50];
    int numero;
    char bairro[50];
    char complemento[50];
    char cep[10];
    char cidade[50];
    char estado[50];
}Endereco;

typedef struct {
    char nome[50];
    Endereco end;
    char tel[12];
}Pessoa;

void cadastrarPessoa(Pessoa *p);
void imprimirPessoa(Pessoa p);


int main() {

    Pessoa pe; 
    cadastrarPessoa(&pe);
    imprimirPessoa(pe);

    return 0;
}

void cadastrarPessoa(Pessoa *p) {

    printf("Nome: ");
    fgets(p->nome, 50, stdin);
    printf("Rua: ");
    fgets(p->end.rua, 50, stdin);
    printf("Numero: ");
    scanf("%i", &p->end.numero);
    fflush(stdin);
    printf("Bairro: ");
    fgets(p->end.bairro, 50, stdin);
    printf("Complemento: ");
    fgets(p->end.complemento, 50, stdin);
    printf("CEP: ");
    fgets(p->end.cep, 50, stdin);
    printf("Cidade: ");
    fgets(p->end.cidade, 50, stdin);
    printf("UF: ");
    fgets(p->end.estado, 50, stdin);
    printf("Telefone: ");
    fgets(p->tel, 12, stdin);
    printf("-----------------------\n");
    printf("Pessoa cadastrada com sucesso!\n");
    printf("-----------------------\n");
}

void imprimirPessoa(Pessoa p) {
    printf("Nome: %s", p.nome);
    printf("Rua: %s", p.end.rua);
    printf("Numero: %i\n", p.end.numero);
    printf("Bairro: %s", p.end.bairro);
    printf("Complemento: %s", p.end.complemento);
    printf("CEP: %s", p.end.cep);
    printf("Cidade: %s", p.end.cidade);
    printf("UF: %s", p.end.estado);
    printf("Telefone: %s", p.tel);
}