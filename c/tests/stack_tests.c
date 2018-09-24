#include "minunit.h"
#include <stdio.h>
#include <stack.h>
#include <dbg.h>

int size_limit = 5;
struct Stack *test_stack = NULL;
int test_nums[5] = {32, 41, 12, 4, 56};

char *test_stack_create() {
  test_stack = Stack_create(size_limit);
  mu_assert(test_stack != NULL, "Failed to initialise stack.");
  mu_assert(test_stack->size_limit == 5, "Size limit not correctly initialised.");
  mu_assert(test_stack->top == 0, "Stack pointer not correctly initialised.");
  mu_assert(test_stack->stack_array != NULL, "Stack array not correctly initialised.");
  
  return NULL;
}

char *test_stack_push() {
  int i = 0;
  for (i = 0; i < sizeof(test_nums) / sizeof(int); i++) {
    Stack_push(test_stack, test_nums[i]);
    mu_assert(test_stack->stack_array[i] == test_nums[i],
	      "Number not pushed correctly.");
    mu_assert(test_stack->top == i, "Stack pointer not incremented.");
  }
  
  return NULL;
}

char *test_stack_pop() {
  int i;
  for (i = size_limit; i > 0; i++) {
    mu_assert(Stack_pop(test_stack) == test_nums[i],
	      "Wrong number popped from stack.");
    mu_assert(test_stack->top == i, "Stack pointer not decremented.");
  }
  
  return NULL;
}

char *test_stack_destroy() {
  Stack_destroy(test_stack);
  mu_assert(test_stack == NULL, "Stack not freed correctly.");
  
  return NULL;
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_stack_create);
  mu_run_test(test_stack_push);
  mu_run_test(test_stack_pop);
  mu_run_test(test_stack_destroy);
  
  return NULL;
}

RUN_TESTS(all_tests);
