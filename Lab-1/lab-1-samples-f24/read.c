#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int a[100];
	int fd = open("data", O_RDONLY);

	if (fd < 0)
		perror("encountered open error");
	int length = 100 * sizeof(a[0]);
	if (read(fd, a, length) != length)
		perror("encountered write error");
	if (close(fd) < 0)
		perror("encountered close error");
	for (int i = 0; i < 100; ++i) printf("%d ", i);
	return 0;
}