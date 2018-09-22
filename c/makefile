CFLAGS=-Wall -Werror -g

all: stack.o stack_main

stack.o: stack.c
stack_main: stack_main.c stack.o

clean:
	rm -rf *~ # Remove Emacs temp files
	rm -rf stack.o stack_main
