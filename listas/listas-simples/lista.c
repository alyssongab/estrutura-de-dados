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
