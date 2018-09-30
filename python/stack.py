#!/usr/bin/env python3

""" This program implements a stack data structure. """

class Stack:

    def __init__(self, stack_size):
        self.stack_array = [0 for x in range(stack_size)]
        self.top = 0
        self.stack_size = stack_size
    
    def stack_push(self, item):
        self.stack_array[self.top] = item
        self.top += 1

    def stack_pop(self):
        self.top -= 1
        last_item = self.stack_array[self.top]
        return last_item

    def print_stack_size(self):
        print(self.stack_size)
