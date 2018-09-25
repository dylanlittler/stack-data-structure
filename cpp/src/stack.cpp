#include <iostream>
#include <vector>
using namespace std;
/**
 * This program is an implementation of a stack data structure
 * in C++ using object-oriented programming.
 */

class Stack {
  int size_limit, top;
  vector<int> stack_vector;
public:
  
  Stack (int);

  void StackPush(int next_item) {
    //if (top >= size_limit) {
    //  cout << "Stack overflow" << endl;
    //  exit(1);
    //}
    stack_vector.push_back(next_item);
    top++;
  }

  int StackPop() {
    //if (top - 1 < 0) {
    //  cout << "Stack underflow" << endl;
    //  exit(1);
    //}
    top--;
    int last_item = stack_vector[top];
    return last_item;
  }
};

Stack::Stack (int sl) {
  size_limit = sl;
  top = 0;
}

int main(int argc, char *argv[]) {
  Stack test_stack (argc - 1);
  int i;

  if (argc < 2) {
    cout << "USAGE: stack NUMS" << endl;
    exit(1);
  }
  
  for (i = 1; i < argc; i++) {
    test_stack.StackPush(stoi(argv[i]));
  }

  for (i = argc - 1; i > 0; i--) {
    cout << "Current item: ";
    cout << test_stack.StackPop() << endl;
  }

  return 0;
}
