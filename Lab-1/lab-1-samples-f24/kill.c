#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	pid_t pid = fork();
	if (pid == 0) {
		printf("Child with pid %d\n", getpid());
		while (1) printf("*");
	} else {
		sleep(1);
		printf("\nParent killing pid %d\n", pid);
		kill(pid, SIGKILL);
	}
	printf("hello\n");
	return 0;
}