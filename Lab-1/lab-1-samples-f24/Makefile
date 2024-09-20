CC=gcc
CFLAGS=-g -Wall
PROGS=chdir dup2 execve exit1 exit2 fork gdb_fib kill leak pipe read wait waitpid write getpid times



%.out: %.c
	$(CC) $< -o $@ $(CFLAGS)


clean:
	rm $(PROGS)
