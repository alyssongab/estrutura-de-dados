#include "static_stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct _static_stack {
    int *data; // vetor de inteiros
    long capacity; // tamanho máximo da pilha
    long top; // controlador do topo da pilha
} StaticStack;

StaticStack *StaticStack_create(long capacity) {
    StaticStack *s = (StaticStack *)calloc(1, sizeof(StaticStack));
    s->capacity = capacity; // define o capacidade
    s->top = -1; // define a pilha como vazia
    s->data = (int *)calloc(s->capacity, sizeof(int)); // cria dinamicamente o vetor

    return s;
}

void StaticStack_destroy(StaticStack **s_ref) {
    StaticStack *s = *s_ref;

    free(s->data); // libera a memória do vetor de elementos
    free(s); // libera a memória da estrutura StaticStack

    *s_ref = NULL; // altera o ponteiro original para null
}

bool StaticStack_is_empty(const StaticStack *s) {
    return s->top == -1;
    // retorna true se for -1 (vazia)
}

bool StaticStack_is_full(const StaticStack *s){
    return s->top == (s->capacity - 1);
}

void StaticStack_push(StaticStack *s, int val){
    if(!StaticStack_is_full(s)){
        s->top++;
        s->data[s->top] = val;
    }
    else{
        fprintf(stderr, "Erro em: 'StaticStack_push'\n");
        printf("Pilha está cheia!\n");
        exit(EXIT_FAILURE);
    }
}

int StaticStack_peek(const StaticStack *s) {
    if(!StaticStack_is_empty(s))
        return s->data[s->top];
    else{
        printf("Pilha está vazia!\n");
        exit(EXIT_FAILURE);
    }
}

int StaticStack_pop(StaticStack *s) {
    if(!StaticStack_is_empty(s)){
        int val = s->data[s->top];
        s->top--;
        return val;
    }
    printf("Pilha está vazia!\n");
    exit(EXIT_FAILURE);
}

void StaticStack_print(const StaticStack *s){
    printf("Capacity: %ld\n", s->capacity);
    printf("Top Index: %ld\n", s->top);

    for(long i = 0; i <= s->top; i++){
        printf("%d, ", s->data[i]);
    }

    puts("");
}