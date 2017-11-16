test: forkin.o
	gcc -g -o test forkin.o

forkin.o: forkin.c forkin.h
	gcc -c forkin.c

run: test
	./test

clean:
	rm *.o