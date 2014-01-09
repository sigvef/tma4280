.PHONY: all
all:
	gcc Matrix.c main.c -o out --std=c99 -g

.PHONY: run
run: all
	./out

debug: all
	gdb -tui out
