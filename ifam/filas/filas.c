// fila.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filas.h"

// Cria uma nova fila vazia
FILA *criarFila() {
    FILA *fila = malloc(sizeof(FILA));
    if (fila != NULL) {
        fila->front = NULL;
        fila->rear = NULL;
        fila->size = 0;
    }
    return fila;
}

// Insere um elemento no final da fila
void enqueue(FILA *fila, void *data, size_t dataSize) {
    NODE *novoNode = malloc(sizeof(NODE));
    if (novoNode == NULL) {
        printf("Erro: Memória insuficiente para inserir elemento.\n");
        exit(EXIT_FAILURE);
    }

    novoNode->data = malloc(dataSize);
    if (novoNode->data == NULL) {
        printf("Erro: Memória insuficiente para alocar dados.\n");
        free(novoNode);
        exit(EXIT_FAILURE);
    }
    memcpy(novoNode->data, data, dataSize);
    novoNode->next = NULL;

    if (fila->rear == NULL) {  // Fila está vazia
        fila->front = novoNode;
        fila->rear = novoNode;
    } else {
        fila->rear->next = novoNode;
        fila->rear = novoNode;
    }
    fila->size++;
}

// Remove e retorna o elemento no início da fila
void *dequeue(FILA *fila) {
    if (isEmpty(fila)) {
        printf("Erro: Tentativa de remoção em uma fila vazia.\n");
        return NULL;
    }

    NODE *tempNode = fila->front;
    void *data = tempNode->data;

    fila->front = tempNode->next;
    if (fila->front == NULL) {  // Se a fila ficou vazia
        fila->rear = NULL;
    }
    free(tempNode);
    fila->size--;
    return data;
}

// Retorna o elemento no início da fila sem removê-lo
void *peek(FILA *fila) {
    if (isEmpty(fila)) {
        printf("Erro: Tentativa de acessar o início de uma fila vazia.\n");
        return NULL;
    }
    return fila->front->data;
}

// Verifica se a fila está vazia
bool isEmpty(FILA *fila) {
    return fila->front == NULL;
}

// Retorna o tamanho atual da fila
int tamanhoFila(FILA *fila) {
    return fila->size;
}

// Libera a memória alocada pela fila
void liberarFila(FILA *fila, void (*freeData)(void *)) {
    while (!isEmpty(fila)) {
        void *data = dequeue(fila);
        if (freeData != NULL) {
            freeData(data);
        }
    }
    free(fila);
}

// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filas.h"

// Função para liberar dados do tipo string
void liberarString(void *data) {
    free(data);
}

// Função de exemplo com fila genérica
int main() {
    FILA *fila = criarFila();

    // Exemplo 1: Inteiros
    printf("Inserindo inteiros na fila...\n");
    int a = 10, b = 20, c = 30;
    enqueue(fila, &a, sizeof(int));
    enqueue(fila, &b, sizeof(int));
    enqueue(fila, &c, sizeof(int));

    printf("Elemento no início da fila (peek): %d\n", *(int *)peek(fila));
    printf("Removendo elemento: %d\n", *(int *)dequeue(fila));
    printf("Tamanho da fila: %d\n", tamanhoFila(fila));

    // Exemplo 2: Strings
    printf("\nInserindo strings na fila...\n");
    char *str1 = strdup("Hello");
    char *str2 = strdup("World");
    char *str3 = strdup("C Programming");
    enqueue(fila, str1, strlen(str1) + 1);
    enqueue(fila, str2, strlen(str2) + 1);
    enqueue(fila, str3, strlen(str3) + 1);

    printf("Elemento no início da fila (peek): %s\n", (char *)peek(fila));
    printf("Removendo elemento: %s\n", (char *)dequeue(fila));
    printf("Tamanho da fila: %d\n", tamanhoFila(fila));

    // Libera a memória da fila e os dados
    liberarFila(fila, liberarString);

    return 0; // ttt
}