#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	
	pid_t pid = fork();

	// If child process
	if (pid == 0){
		printf("Child process id: %d\n", getpid());
		printf("Parent process id: %d\n", getppid());
	}
	wait(NULL);	
	return 0;
}
