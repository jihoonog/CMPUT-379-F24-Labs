#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int a[100];
	for (int i = 0; i < 100; ++i) a[i] = i;
	// create file "data", truncate it, open it for write
	// operation, set user permissions to rw
	int fd = open("data", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);

	if (fd < 0)
		perror("encountered open error");
	int length = 100 * sizeof(a[0]);
	if (write(fd, a, length) != length)
		perror("encountered write error");
	if (close(fd) < 0)
		perror("encountered close error");
	return 0;
}