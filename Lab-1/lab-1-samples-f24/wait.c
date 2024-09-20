#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("Parent ID: %d\n", getpid());
	pid_t pid_1 = fork();
	if (pid_1 == 0){
		printf("Child 1 with pid %d\n", getpid());
		printf("Child 1 sleeping for 5 secs\n");
		sleep(5);
		printf("Child 1 done\n");
		fflush(NULL);
		_exit(0);
	
	}

	pid_t pid_2 = fork();
	if (pid_2 == 0){
		printf("Child 2 with pid %d\n", getpid());
		printf("Child 2 sleeping for 30 secs\n");
		sleep(30);
		printf("Child 2 done\n");
		fflush(NULL);
		_exit(0);
	
	}
	wait(NULL);
	return 0;
} 
