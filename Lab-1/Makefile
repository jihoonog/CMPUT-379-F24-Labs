CC = gcc
CFLAGS = -g -Wall


leaky_prog.o: leaky_prog.c
	$(CC) -c leaky_prog.c $(CFLAGS) 

leaky_prog: leaky_prog.o
	$(CC) -o leaky_prog leaky_prog.o $(CFLAGS)

clean:
	rm leaky_prog.o leaky_prog
