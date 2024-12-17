#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nome[50];
    struct Node *prox;
} Node;

typedef struct Fila {
    Node *inicio;
    Node *fim;
} Fila;

Fila* criaFila() {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void enfileirar(Fila *fila, char *nome) {
    Node *novo = (Node*)malloc(sizeof(Node));
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    if (fila->fim == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

void desenfileirar(Fila *fila) {
    if (fila->inicio != NULL) {
        Node *temp = fila->inicio;
        printf("Cliente %s atendido!\n\n", temp->nome);
        fila->inicio = fila->inicio->prox;
        if (fila->inicio == NULL) fila->fim = NULL;
        free(temp);
    }
}

void mostraFila(Fila *fila) {
    Node *atual = fila->inicio;
    while (atual != NULL) {
        printf("%s ", atual->nome);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {

    system("clear");
    Fila *caixa1 = criaFila();
    Fila *caixa2 = criaFila();
    Fila *caixa3 = criaFila();
    int opcao, caixa;
    char nome[50];

    do {
        printf("1. Adicionar cliente\n");
        printf("2. Atender cliente\n");
        printf("3. Mostrar filas\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            system("clear");
            printf("Nome do cliente: ");
            scanf("%s", nome);
            printf("Escolha o caixa (1, 2, 3): ");
            scanf("%d", &caixa);
            if (caixa == 1) enfileirar(caixa1, nome);
            else if (caixa == 2) enfileirar(caixa2, nome);
            else if (caixa == 3) enfileirar(caixa3, nome);
            system("clear");
        } else if (opcao == 2) {
            system("clear");
            printf("Escolha o caixa (1, 2, 3): ");
            scanf("%d", &caixa);
            if (caixa == 1) desenfileirar(caixa1);
            else if (caixa == 2) desenfileirar(caixa2);
            else if (caixa == 3) desenfileirar(caixa3);
        } else if (opcao == 3) {
            system("clear");
            printf("Caixa 1: ");
            mostraFila(caixa1);
            printf("Caixa 2: ");
            mostraFila(caixa2);
            printf("Caixa 3: ");
            mostraFila(caixa3);
            puts("Pressione <Enter> para continuar");
            getchar();
            getchar();
            system("clear");
        }
    } while (opcao != 0);

    free(caixa1);
    free(caixa2);
    free(caixa3);

    printf("\nSaindo...\n");

    return 0;
}
