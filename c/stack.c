#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* This program implements a stack data structure. */

/* Stack struct definition with counter, and pointer
 * to dynamically sized array of ints. */
struct Stack {
  int size_limit;
  int top;
  int *stack_array;
};

void Destroy_stack(struct Stack *stack);

void die(char *message, struct Stack *stack) {
  if (errno)
    perror(message);
  else
    printf("ERROR: %s\n", message);
  Destroy_stack(stack);
  exit(1);
}

void push(struct Stack *stack, int next_item) {
  /* Pushes next integer onto array. */
  if (stack->top >= stack->size_limit)
    die("Stack overflow", stack);

  stack->stack_array[stack->top] = next_item;
  stack->top++;
}

int pop(struct Stack *stack) {
  /* Pops most recently added integer off array. */
  if (stack->top <= 0)
    die("Stack underflow", stack);

  int last_item = stack->stack_array[stack->top];
  stack->top--;
  
  return last_item;
}

struct Stack *Create_stack(int size_limit) {
  /* Initialises memory for Stack struct and returns pointer. */
  struct Stack *new_stack = malloc(size_limit + (sizeof(int) * 2));
  new_stack->size_limit = size_limit;
  new_stack->stack_array = malloc(size_limit);
  return new_stack;
}

void Destroy_stack(struct Stack *stack) {
  /* Frees memory from stack. */
  if (stack) {
    if (stack->stack_array)
      free(stack->stack_array);
    free(stack);
  }
}

int main(int argc, char *argv[]) {
  return 0;
}
