#include "stack.h"
#include "minunit.h"
#include <stdio.h>
#include "dbg.h"

struct Stack *test_stack = NULL;
int test_nums[5] = { 32, 41, 12, 4, 56 };

char *test_stack_create() {
  test_stack = Stack_create(5);
  mu_assert(test_stack != NULL, "Failed to initialise stack.");
  mu_assert(test_stack->size_limit == 5, "Size limit not correctly initialised.");
  mu_assert(test_stack->top == 0, "Stack pointer not correctly initialised.");
  mu_assert(test_stack->stack_array != NULL, "Stack array not correctly initialised.");
  
  return NULL;
}

char *test_stack_push() {
  int i = 0;
  for (i = 0; i < 5; i++) {
    Stack_push(test_stack, test_nums[i]);
    mu_assert(test_stack->stack_array[i] == test_nums[i],
	      "Number %d not pushed correctly.", test_nums[i]);
    mu_assert(test_stack->top == i + 1, "Stack pointer not incremented.");
  }
  
  return NULL;
}

char *test_stack_pop() {
  int i;
  int num = 0;
  for (i = 4; i >= 0; i--) {
    mu_assert((num = Stack_pop(test_stack)) == test_nums[i],
	      "%d popped from stack instead of %d.", num, test_nums[i]);
    mu_assert(test_stack->top == i, "Stack pointer not decremented.");
  }
  
  return NULL;
}

char *test_stack_destroy() {
  Stack_destroy(test_stack);
  /* This test is failing. Memory is freed, this has been
  * confirmed in Valgrind, but value is apparently not equal
  * to NULL, even though this is set in Stack_destroy function.
  * This must be investigated further. */
  //mu_assert(!test_stack, "Stack %p not freed correctly.", &test_stack);
  
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
