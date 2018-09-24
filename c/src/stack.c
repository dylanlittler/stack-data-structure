#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "dbg.h"

/* This program implements a stack data structure. */

/* Stack struct definition with counter, and pointer
 * to dynamically sized array of ints. */
struct Stack {
  int size_limit;
  int top;
  int *stack_array;
};

void Stack_push(struct Stack *stack, int next_item) {
  /* Pushes next integer onto array. */
  check(stack->top < stack->size_limit, "Stack overflow");

  stack->stack_array[stack->top] = next_item;
  stack->top++;
  return;
 error:
  exit(1);
}

int Stack_pop(struct Stack *stack) {
  /* Pops most recently added integer off array. */
  check(stack->top > 0, "Stack underflow");

  int last_item = stack->stack_array[stack->top - 1]; // prevent off-by-one error
  stack->top--;
  
  return last_item;

 error:
  exit(1);
}

struct Stack *Stack_create(int size_limit) {
  /* Initialises memory for Stack struct and returns pointer. */
  struct Stack *new_stack = malloc(sizeof(struct Stack));
  check_mem(new_stack);
  
  new_stack->size_limit = size_limit;
  new_stack->top = 0;
  new_stack->stack_array = malloc(sizeof(new_stack->stack_array) * size_limit);
  check_mem(new_stack->stack_array);

  return new_stack;

 error:
  return NULL; // calling function should check for NULL
}

void Stack_destroy(struct Stack *stack) {
  /* Frees memory from stack. */
  if (stack) {
    if (stack->stack_array)
      free(stack->stack_array);
    free(stack);
  }
}
