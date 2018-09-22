#ifndef _stack_h_
#define _stack_h_

/**
 * This header includes functions from stack.c
 * to make them available to other programs.
 */

void Stack_destroy(struct Stack *stack);

struct Stack *Stack_create(int size limit);

void Stack_push(struct Stack *stack, int next_item);

int Stack_pop(struct Stack *stack);

#endif
