#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	fork(); 
	fork(); 
	fork(); 
	printf("hello\n"); 
	return 0; 
} 