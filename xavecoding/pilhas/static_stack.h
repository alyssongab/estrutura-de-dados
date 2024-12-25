#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _static_stack StaticStack;

StaticStack *StaticStack_create(long capacity);
void StaticStack_destroy(StaticStack **s_ref);

bool StaticStack_is_empty(const StaticStack *s);
bool StaticStack_is_full(const StaticStack *s);

void StaticStack_push(StaticStack *s, int val);
int StaticStack_peek(const StaticStack *s);
int StaticStack_pop(StaticStack *s);

void StaticStack_print(const StaticStack *s);

#endif