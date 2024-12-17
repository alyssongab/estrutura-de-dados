#include <stdio.h>
#include "lista.h"
#include <stdbool.h>

int main(){
    LinkedList *L = LinkedList_create();

    bool LinkedList_is_empty(const LinkedList *L);
    LinkedList_add_first(L, 5);
    LinkedList_print(L);
    LinkedList_add_first(L, 4);
    LinkedList_print(L);
    LinkedList_add_first(L, 2);
    LinkedList_print(L);
    LinkedList_add_first(L, 10);
    LinkedList_print(L);

    return 0;

}