CC=gcc

INCDIR=./include
SRCDIR=./src

CFLAGS=-g -lcjson -Wall -Wextra

testcomp:
	$(CC) src/parser.c $(CFLAGS) -o testprog

test:
	make testcomp
	./testprog minefighterz/project.json
	echo "OUTPUT:"
	cat out.c
	rm out.c testprog

oops:
	make testcomp
	valgrind ./testprog minefighterz/project.json

oops2:
	make testcomp
	./testprog
	gdb testprog core
