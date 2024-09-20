#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	int file_desc = open("test.txt", O_CREAT | O_WRONLY);
	if(file_desc < 0) 
		printf("Error opening the file\n"); 
	dup2(file_desc, 1);
	printf("Tester\n");
	close(file_desc);

	return 0; 
} 