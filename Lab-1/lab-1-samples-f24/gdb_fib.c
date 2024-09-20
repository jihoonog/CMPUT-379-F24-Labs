#include <stdio.h>
int foo = 0;

void mystery(void) {
	foo++;
	if (foo == 19234) {
		int *p = 0;
		*p = 0;
	}
}

int fib(int n) {
	mystery();
	if (n < 2) {
		return n;
	}
	return fib(n-1) + fib(n-2);
}

int main(int argc, char *argv[]) {
	printf("%d\n", fib(20));
}