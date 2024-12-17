#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Cliente
typedef struct {
    int id;
    char nome[100];
    int idade;
    double saldo;
} Cliente;

// Função para adicionar um novo cliente
Cliente* adicionar_cliente(Cliente *clientes, int *n) {
    (*n)++;
    clientes = (Cliente*)realloc(clientes, (*n) * sizeof(Cliente));
    if (clientes == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    Cliente novo_cliente;
    novo_cliente.id = *n;  // O ID será o número do cliente
    printf("Digite o nome do cliente: ");
    getchar();  // Limpar o buffer do teclado
    fgets(novo_cliente.nome, 100, stdin);
    novo_cliente.nome[strcspn(novo_cliente.nome, "\n")] = 0;  // Remover o \n
    printf("Digite a idade do cliente: ");
    scanf("%d", &novo_cliente.idade);
    printf("Digite o saldo do cliente: ");
    scanf("%lf", &novo_cliente.saldo);

    clientes[(*n) - 1] = novo_cliente;
    printf("Cliente adicionado com sucesso!\n\n");

    return clientes;
}

// Função para exibir todos os clientes
void exibir_clientes(Cliente *clientes, int n) {
    if (n == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    printf("Lista de clientes:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", clientes[i].id);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Saldo: %.2lf\n", clientes[i].saldo);
        printf("---------------------\n");
    }
}

// Função para atualizar os dados de um cliente
void atualizar_cliente(Cliente *clientes, int n) {
    if (n == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do cliente que deseja atualizar: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (clientes[i].id == id) {
            printf("Atualizando dados do cliente com ID %d...\n", id);
            printf("Digite o novo nome do cliente: ");
            getchar();  // Limpar o buffer do teclado
            fgets(clientes[i].nome, 100, stdin);
            clientes[i].nome[strcspn(clientes[i].nome, "\n")] = 0;  // Remover o \n
            printf("Digite a nova idade do cliente: ");
            scanf("%d", &clientes[i].idade);
            printf("Digite o novo saldo do cliente: ");
            scanf("%lf", &clientes[i].saldo);
            printf("Dados atualizados com sucesso!\n\n");
            return;
        }
    }
    printf("Cliente com ID %d não encontrado.\n", id);
}

// Função para deletar um cliente
Cliente* deletar_cliente(Cliente *clientes, int *n) {
    if (*n == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return clientes;
    }

    int id;
    printf("Digite o ID do cliente que deseja deletar: ");
    scanf("%d", &id);

    for (int i = 0; i < *n; i++) {
        if (clientes[i].id == id) {
            printf("Deletando cliente com ID %d...\n", id);
            // Deslocar os elementos para remover o cliente
            for (int j = i; j < *n - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            (*n)--;

            // Realocar memória para o novo tamanho
            clientes = (Cliente*)realloc(clientes, (*n) * sizeof(Cliente));
            printf("Cliente deletado com sucesso!\n\n");
            return clientes;
        }
    }
    printf("Cliente com ID %d não encontrado.\n", id);
    return clientes;
}

// Função principal
int main() {
    Cliente *clientes = NULL;
    int n = 0;
    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Adicionar cliente\n");
        printf("2. Exibir clientes\n");
        printf("3. Atualizar cliente\n");
        printf("4. Deletar cliente\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                clientes = adicionar_cliente(clientes, &n);
                break;
            case 2:
                exibir_clientes(clientes, n);
                break;
            case 3:
                atualizar_cliente(clientes, n);
                break;
            case 4:
                clientes = deletar_cliente(clientes, &n);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    // Liberação da memória antes de sair
    free(clientes);

    return 0;
}