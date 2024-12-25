#include <stdio.h>
#include "static_stack.h"

int main(){
    StaticStack *S = StaticStack_create(5);
    int top_val;

    StaticStack_print(S);

    // puts("\nPeek:");
    // top_val = StaticStack_peek(S);
    // printf("top_val = %d\n", top_val);

    // puts("\nPop:");
    // top_val = StaticStack_pop(S);
    // printf("top_val = %d\n", top_val);

    puts("\nPush: 0, 10, 20");
    StaticStack_push(S, 0);
    StaticStack_push(S, 10);
    StaticStack_push(S, 20);
    StaticStack_print(S);

    puts("\nPeek:");
    top_val = StaticStack_peek(S);
    printf("top_val = %d\n", top_val);
    StaticStack_print(S);

    puts("\nPop:");
    top_val = StaticStack_pop(S);
    printf("top_val = %d\n", top_val);
    StaticStack_print(S);

    puts("Push: 20, 30, 40");
    StaticStack_push(S, 20);
    StaticStack_push(S, 30);
    StaticStack_push(S, 40);
    StaticStack_print(S);

    puts("\nPush: 50");
    StaticStack_push(S, 50);
    StaticStack_print(S);

    StaticStack_destroy(&S);

    return 0;
}