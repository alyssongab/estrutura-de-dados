#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100

// Definindo a estrutura de dados
typedef struct {
    char rua[50];
    int numero;
    char complemento[30];
    char bairro[30];
    char cep[15];
    char cidade[30];
    char estado[3];
    char pais[30];
} Endereco;

typedef struct {
    int ddd;
    char numero[15];
} Telefone;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[50];
    char email[50];
    Endereco endereco;
    Telefone telefone;
    Data aniversario;
    char observacoes[100];
} Pessoa;

// Declaração da agenda
Pessoa agenda[MAX_CONTATOS];
int total_contatos = 0;

// Funções auxiliares

void inserir_pessoa(Pessoa nova_pessoa) {
    int i = total_contatos - 1;
   
    // Insere em ordem alfabética
    while (i >= 0 && strcmp(nova_pessoa.nome, agenda[i].nome) < 0) {
        agenda[i + 1] = agenda[i];
        i--;
    }
   
    agenda[i + 1] = nova_pessoa;
    total_contatos++;
}

void busca_por_nome(char *nome) {
    int encontrado = 0;
    for (int i = 0; i < total_contatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            printf("Nome: %s, E-mail: %s, Telefone: (%d) %s\n", agenda[i].nome, agenda[i].email, agenda[i].telefone.ddd, agenda[i].telefone.numero);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum contato encontrado com o nome %s.\n", nome);
    }
}

void busca_por_mes_aniversario(int mes) {
    int encontrado = 0;
    for (int i = 0; i < total_contatos; i++) {
        if (agenda[i].aniversario.mes == mes) {
            printf("Nome: %s, E-mail: %s, Telefone: (%d) %s\n", agenda[i].nome, agenda[i].email, agenda[i].telefone.ddd, agenda[i].telefone.numero);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum contato faz aniversario no mes %d.\n", mes);
    }
}

void busca_por_dia_mes_aniversario(int dia, int mes) {
    int encontrado = 0;
    for (int i = 0; i < total_contatos; i++) {
        if (agenda[i].aniversario.dia == dia && agenda[i].aniversario.mes == mes) {
            printf("Nome: %s, E-mail: %s, Telefone: (%d) %s\n", agenda[i].nome, agenda[i].email, agenda[i].telefone.ddd, agenda[i].telefone.numero);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum contato faz aniversario no dia %d/%d.\n", dia, mes);
    }
}

void retira_pessoa(char *nome) {
    int i, j;
    for (i = 0; i < total_contatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            // Remove a pessoa e desloca os elementos
            for (j = i; j < total_contatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            total_contatos--;
            printf("Contato removido com sucesso.\n");
            return;
        }
    }
    printf("Contato com o nome %s não encontrado.\n", nome);
}

void imprime_agenda(int modo_completo) {
    for (int i = 0; i < total_contatos; i++) {
        printf("Nome: %s, Telefone: (%d) %s, E-mail: %s\n", agenda[i].nome, agenda[i].telefone.ddd, agenda[i].telefone.numero, agenda[i].email);
        if (modo_completo) {
            printf("Endereco: %s, %d, %s, %s, %s, %s, %s\n",
                   agenda[i].endereco.rua, agenda[i].endereco.numero,
                   agenda[i].endereco.complemento, agenda[i].endereco.bairro,
                   agenda[i].endereco.cep, agenda[i].endereco.cidade,
                   agenda[i].endereco.estado);
            printf("Data de aniversario: %02d/%02d/%d\n", agenda[i].aniversario.dia, agenda[i].aniversario.mes, agenda[i].aniversario.ano);
            printf("Observacoes: %s\n", agenda[i].observacoes);
        }
        printf("-----------------------------\n");
    }
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu da Agenda ---\n");
        printf("1. Inserir pessoa\n");
        printf("2. Buscar por primeiro nome\n");
        printf("3. Buscar por mes de aniversario\n");
        printf("4. Buscar por dia e mes de aniversario\n");
        printf("5. Retirar pessoa\n");
        printf("6. Imprimir agenda (nome, telefone e email)\n");
        printf("7. Imprimir agenda (todos os dados)\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        char nome[50];
        int mes, dia;

        switch (opcao) {
            case 1:
                if (total_contatos < MAX_CONTATOS) {
                    Pessoa p;
                    printf("Nome: ");
                    scanf(" %[^\n]", p.nome);
                    printf("E-mail: ");
                    scanf(" %[^\n]", p.email);
                    printf("Telefone (DDD Numero): ");
                    scanf("%d %s", &p.telefone.ddd, p.telefone.numero);
                    printf("Aniversario (Dia Mes Ano): ");
                    scanf("%d %d %d", &p.aniversario.dia, &p.aniversario.mes, &p.aniversario.ano);
                    printf("Observacoes: ");
                    scanf(" %[^\n]", p.observacoes);
                    inserir_pessoa(p);
                } else {
                    printf("Agenda cheia!\n");
                }
                break;

            case 2:
                printf("Digite o nome: ");
                scanf(" %[^\n]", nome);
                busca_por_nome(nome);
                break;

            case 3:
                printf("Digite o mes: ");
                scanf("%d", &mes);
                busca_por_mes_aniversario(mes);
                break;

            case 4:
                printf("Digite o dia e o mes: ");
                scanf("%d %d", &dia, &mes);
                busca_por_dia_mes_aniversario(dia, mes);
                break;

            case 5:
                printf("Digite o nome a ser removido: ");
                scanf(" %[^\n]", nome);
                retira_pessoa(nome);
                break;

            case 6:
                imprime_agenda(0);
                break;

            case 7:
                imprime_agenda(1);
                break;

            case 8:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 8);
}

int main() {
    menu();
    return 0;
}