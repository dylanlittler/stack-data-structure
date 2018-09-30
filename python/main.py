#!/usr/bin/env python3
import argparse
import stack

parser = argparse.ArgumentParser()
parser.add_argument('integers', type=int, nargs='*',
                    help='integers to be pushed onto the stack')
args = parser.parse_args()

test_stack = stack.Stack(len(args.integers))

for item in args.integers:
    test_stack.stack_push(item)

for item in test_stack.stack_array:
    print("Current item: {}".format(test_stack.stack_pop()))


