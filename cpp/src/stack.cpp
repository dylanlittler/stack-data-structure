#include <iostream>
using namespace std;
/**
 * This program is an implementation of a stack data structure
 * in C++ using object-oriented programming.
 */

class Stack {
  int size_limit, top;
  int *stack_array;
public:
  
  Stack (int);
  
  void StackPush(int next_item) {
    if (top + 1 >= size_limit) {
      cout << "Stack overflow" << endl;
      exit(1);
    }
    stack_array[top] = next_item;
    top++;
  }

  int StackPop() {
    if (top - 1 <= 0) {
      cout << "Stack underflow" << endl;
      exit(1);
    }
    top--;
    int last_item = stack_array[top];
    return last_item;
  }
};

Stack::Stack (int sl) {
  size_limit = sl;
  top = 0;
  stack_array = new int[sl];
}

int main(int argc, char *argv[]) {
  Stack test_stack (argc - 1);
  int i;

  for (i = 1; i < argc; i++) {
    test_stack.StackPush(stoi(argv[i]));
  }

  for (i = argc - 1; i > 0; i--) {
    cout << "Current item: ";
    cout << test_stack.StackPop();
  }

  return 0;
}
