#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	char *args[]={"./fork",NULL}; 
	execve(args[0], args, NULL); 
	printf("End on demo"); 

	return 0; 
} 
