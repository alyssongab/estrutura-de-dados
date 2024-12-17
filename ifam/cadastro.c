#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Cadastro
typedef struct {
    char nome[100];
    int idade;
    char endereco[200];
} Cadastro;

// Função que aloca um vetor de N elementos da estrutura Cadastro e preenche os dados
Cadastro* criar_cadastro(int n) {
    // Alocação dinâmica do vetor de estruturas Cadastro
    Cadastro* cadastros = (Cadastro*)malloc(n * sizeof(Cadastro));
    if (cadastros == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    // Preenchimento dos dados para cada pessoa
    for (int i = 0; i < n; i++) {
        printf("Cadastro %d:\n", i + 1);

        printf("Digite o nome: ");
        fgets(cadastros[i].nome, 100, stdin);
        cadastros[i].nome[strcspn(cadastros[i].nome, "\n")] = 0; // Remove newline

        printf("Digite a idade: ");
        scanf("%d", &cadastros[i].idade);
        getchar(); // Limpar o buffer após ler o inteiro

        printf("Digite o endereço: ");
        fgets(cadastros[i].endereco, 200, stdin);
        cadastros[i].endereco[strcspn(cadastros[i].endereco, "\n")] = 0; // Remove newline

        printf("\n");
    }

    return cadastros;
}

int main() {
    int n;

    // Solicitação do número de cadastros
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); // Limpar o buffer após a leitura de número

    // Chamada da função para criar e preencher o vetor de cadastros
    Cadastro* cadastros = criar_cadastro(n);

    // Exibição dos dados cadastrados
    printf("Dados cadastrados:\n");
    for (int i = 0; i < n; i++) {
        printf("Cadastro %d:\n", i + 1);
        printf("Nome: %s\n", cadastros[i].nome);
        printf("Idade: %d\n", cadastros[i].idade);
        printf("Endereço: %s\n", cadastros[i].endereco);
        printf("\n");
    }

    // Liberação da memória alocada
    free(cadastros);

    return 0;
}