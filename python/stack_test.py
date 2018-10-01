#!/usr/bin/env python3
import unittest
import stack

test_items = [34, 54, 23, 87, 12, 90, 435]
test_stack = stack.Stack(len(test_items))
for item in test_items:
    test_stack.stack_push(item)

class TestStackMethods(unittest.TestCase):

    def test_pop(self):
        index = len(test_items) - 1
        for i in range(len(test_items)):
            self.assertEqual(test_stack.stack_pop(), test_items[index])
            index -= 1

if __name__ == '__main__':
    unittest.main()
