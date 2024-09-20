#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int *p = (int*)malloc(16 * sizeof(int));
	printf("%d\n", p[0]);

	return 0;
}
