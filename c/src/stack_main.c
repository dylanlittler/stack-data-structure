#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "dbg.h"

/**
 * This program will run the functions from stack.c for testing purposes.
 */

int main(int argc, char *argv[]) {
  int i = 0;
  int current_item = 0;

  if (argc < 2) {
    printf("USAGE: stack.c NUMS\n");
    exit(1);
  }

  int stack_size = argc - 1;

  struct Stack *test_stack = Stack_create(stack_size);
  // Stack_create returns NULL on error
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
  Stack_destroy(test_stack);
  return 1;
}
