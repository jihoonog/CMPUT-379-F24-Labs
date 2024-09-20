#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	char msg[] = "Tester", buf[100];
	int p[2];

	pipe(p);

	write(p[1], msg, sizeof(msg));
	read(p[0], buf, sizeof(msg));
	printf("%s\n", buf);

	return 0; 
} 