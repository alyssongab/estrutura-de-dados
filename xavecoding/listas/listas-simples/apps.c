#include <stdio.h>
#include "lista.h"
#include <stdbool.h>

int main(){
    LinkedList *L = LinkedList_create();

    // bool LinkedList_is_empty(const LinkedList *L);
    // LinkedList_add_first(L, 5);
    // LinkedList_print(L);
    // LinkedList_add_first(L, 4);
    // LinkedList_print(L);
    // LinkedList_add_first(L, 2);
    // LinkedList_print(L);
    // LinkedList_add_first(L, 10);
    // LinkedList_print(L);

    LinkedList_add_last(L, 10);
    LinkedList_add_last(L, 2);
    LinkedList_add_last(L, 4);
    LinkedList_add_last(L, 5);
    LinkedList_add_last(L, 7);
    LinkedList_print(L);

    LinkedList_remove(L, 3);
    LinkedList_print(L);

    // Após a remoção
    // printf("Removendo o primeiro elemento...\n");
    // LinkedList_remove(L, 10);
    // LinkedList_print(L);

    return 0;

}