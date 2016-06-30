CFLAGS = -g -Wall

all: hello

hello: hello.o util.o slist.o dlist.o stack.o queue.o bintree.o bstree.o
	gcc $(CFLAGS) hello.o util.o slist.o dlist.o stack.o queue.o bintree.o bstree.o -o hello 

hello.o: hello.c
	gcc $(CFLAGS) -c hello.c

util.o: util.c
	gcc $(CFLAGS) -c util.c

slist.o: slist.c
	gcc $(CFLAGS) -c slist.c

dlist.o: dlist.c
	gcc $(CFLAGS) -c dlist.c

stack.o: stack.c
	gcc $(CFLAGS) -c stack.c

queue.o: queue.c
	gcc $(CFLAGS) -c queue.c

bintree.o: bintree.c
	gcc $(CFLAGS) -c bintree.c

bstree.o: bstree.c
	gcc $(CFLAGS) -c bstree.c

clean:
	rm *o 
