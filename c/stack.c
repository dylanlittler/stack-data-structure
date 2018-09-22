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

void Stack_destroy(struct Stack *stack);

void die(char *message, struct Stack *stack) {
  if (errno)
    perror(message);
  else
    printf("ERROR: %s\n", message);
  Stack_destroy(stack);
  exit(1);
}

void Stack_push(struct Stack *stack, int next_item) {
  /* Pushes next integer onto array. */
  if (stack->top >= stack->size_limit)
    die("Stack overflow", stack);

  stack->stack_array[stack->top] = next_item;
  stack->top++;
}

int Stack_pop(struct Stack *stack) {
  /* Pops most recently added integer off array. */
  if (stack->top <= 0)
    die("Stack underflow", stack);

  int last_item = stack->stack_array[stack->top - 1]; // prevent off-by-one error
  stack->top--;
  
  return last_item;
}

struct Stack *Stack_create(int size_limit) {
  /* Initialises memory for Stack struct and returns pointer. */
  struct Stack *new_stack = malloc(sizeof(struct Stack));
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

int main(int argc, char *argv[]) {
  int i = 0;
  int current_item = 0;
  
  if (argc < 2) {
    printf("Need stack.c, [items]\n");
    exit(1);
  }
    
  int stack_size = argc - 1;
  
  struct Stack *test_stack = Stack_create(stack_size);
  check(test_stack != NULL, "Stack not initialised");
  
  for (i = 1; i < argc; i++) {
    Stack_push(test_stack, atoi(argv[i]));
  }

  for (i = 1; i < argc; i++) {
    current_item = Stack_pop(test_stack);
    printf("Current_item: %d\n", current_item);
  }

  Stack_destroy(test_stack);
  return 0;

 error:
  return 1;
}
