#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// estrutura do nó (Onde irá ficar os elementos e ponteiro next)
typedef struct _snode{
    int val;
    struct _snode *next;
}SNode;

// estrutura da lista
typedef struct _linked_list{
    SNode *begin;
    SNode *end;
}LinkedList;

// Cria o começo da lista
LinkedList *LinkedList_create(){
    LinkedList *L = (LinkedList*)calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;

    return L;
}

bool LinkedList_is_empty(const LinkedList *L){
    return (L->begin == NULL && L->end == NULL);
}

// Cria a "caixinha" , o nó
SNode *SNode_create(int val){
    SNode *snode = (SNode*)calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;

    return snode;
}

// adiciona elemento na cabeça da lista
// void LinkedList_add_first(LinkedList *L, int val){
//     SNode *p = SNode_create(val);
//     p->next = L->begin;
//     L->begin = p;

// }

void LinkedList_add_first(LinkedList *L, int val){
    SNode *p = SNode_create(val); // novo nó a ser inserido
    p->next = L->begin;
    
    if(LinkedList_is_empty(L)){
        L->end = p;
    }
    
    L->begin = p;

    printf("L->end: %i\n", L->end->val);
   
}

// imprime os elementos da lista
void LinkedList_print(const LinkedList *L){
    SNode *p = L->begin;

    printf("L -> ");

    // enquanto p aponta para um nó
    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}

// adiciona um elemento na cauda da lista (forma mais lenta)
void LinkedList_add_last_slow(LinkedList *L, int val){
    SNode *q = SNode_create(val);

   // lista vazia
    if(LinkedList_is_empty(L)){
        L->begin = q; 
    }
    else {
        SNode *p = L->begin;

        // p->next != null significa que existe um proximo ponteiro
        while(p->next != NULL) {
            p = p->next;
        }
        // nesse momento o ponteiro p aponta para o último nó
        p->next = q;
    }
}

// adiciona um elemento na cauda da lista (forma mais lenta)
void LinkedList_add_last(LinkedList *L, int val){
    SNode *q = SNode_create(val);

   // lista vazia
    if(LinkedList_is_empty(L)){
        L->begin = L->end = q;
    }
    else {
        L->end->next = q;
        L->end = L->end->next;
    }
}

void LinkedList_remove(LinkedList *L, int val){
    if(!LinkedList_is_empty(L)){
        // caso 1 - elemento está na cabeça da lista
        if(L->begin->val == val){
            SNode *pos = L->begin; // ponteiro que aponta para o nó da cabeça

            // Verifica se a lista tem somente 1 elemento
            if(L->begin == L->end) {
                L->end = NULL;
            }

            L->begin = L->begin->next;
            free(pos); // libera o ponteiro pos, removendo assim o nó desejado
        }
        // caso 3 - elemento no final da lista
        else if(L->end->val == val){
            SNode *tail = L->end;
            SNode *prev = L->begin;
        }
        // caso 2 - elemento está no meio da lista
        else {
            SNode *prev = L->begin; // aponta para o nó da cabeça
            SNode *pos = L->begin->next;// aponta para o segundo nó

            while(pos != NULL && pos->val != val){
                // ambos apontam para o próximo nó (move os ponteiros)
                prev = pos;
                pos = pos->next;
            }

            // um nó com valor val foi encontrado e é apontado pelo ponteiro "pos"
            if(pos != NULL) {
                // corrigindo o encadeamento
                prev->next = pos->next;
                free(pos);
            }
        }
    }
}
