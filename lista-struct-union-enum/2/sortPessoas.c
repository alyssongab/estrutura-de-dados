#include <stdio.h>
#include <stdlib.h>

/* Utilizando estrutura, fazer um programa em C que permita a entrada de nome,
endereço e telefone de 5 pessoas e os imprima em ordem alfabética. */

typedef struct {
    char rua[30];
    int numero;
    char bairro[30];
}Endereco;

typedef struct {
    char nome[100];
    Endereco end;
    char telefone[20];
}Pessoa;

void inserir(Pessoa *p, int tam);
void imprimirEmOrdem(Pessoa *p, int tam);

int main() {

    Pessoa p[5];
    inserir(&p, 5);
    imprimirEmOrdem(&p,5);

    return 0;
}

void inserir(Pessoa *p, int tam) {
    for(int i = 0; i < 5; i++) {
        printf("Nome: ");
        fgets(p->nome, 100, stdin);
        printf("\n");
    }
}

void imprimirEmOrdem(Pessoa *p, int tam) {
    printf("Nomes em ordem alfabetica:\n");
    for(int i = 0; i < 5; i++) {
        
    }
}
