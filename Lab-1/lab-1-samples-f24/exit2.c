#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	for (int i = 0; i < 5; i++) {
		if (fork() == 0) {
			printf("Child %d with pid %d\n", i, getpid());
			fflush(NULL);
			_exit(0);
		}
	}
	printf("hello\n");
	return 0;
} 
