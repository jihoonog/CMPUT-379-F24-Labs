#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	pid_t pid_1 = fork();

	if (pid_1 == 0){
		printf("Child 1 with pid %d\n", getpid());
		printf("Child 1 sleeping for 2 secs\n");
		sleep(2);
		printf("Child 1 done\n");
		fflush(NULL);
		_exit(0);
	
	}

	pid_t pid_2 = fork();
	if (pid_2 == 0){
		printf("Child 2 with pid %d\n", getpid());
		printf("Child 2 sleeping for 10 secs\n");
		sleep(10);
		printf("Child 2 done\n");
		fflush(NULL);
		_exit(0);
	
	}
	while (waitpid(pid_2, NULL, 0) > 0);
	printf("Child 2 finished\n");
	return 0;
} 
