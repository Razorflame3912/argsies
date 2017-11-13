all: parse.c
	gcc parse.c
run: all
	./a.out
clean:
	rm *.out
	rm *~
