#ifndef LISTA_H
#define LISTA_H

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

SNode *SNode_create(int val);

LinkedList *LinkedList_create();

void LinkedList_destroy(LinkedList **L_ref);

void LinkedList_add_first(LinkedList *L, int val);

void LinkedList_print(const LinkedList *L);

void LinkedList_add_last_slow(LinkedList *L, int val);

void LinkedList_add_last(LinkedList *L, int val);

void LinkedList_remove(LinkedList *L, int val);

void LinkedList_remove_better(LinkedList *L, int val);

#endif