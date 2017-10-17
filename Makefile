all: BSTDemo

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

BSTDemo: BST.o BSTDemo.o
	cc -o $@ &^

BST.o: BST.c BST.h
	cc -c $(CFLAGS) BST.c

BSTDemo.o: BSTDemo.c BST.h
	cc -c $(CFLAGS) BST.c

clean:
	rm -f *.o BSTDemo

demo: BSTDemo
	./BSTDemo
