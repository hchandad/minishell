#include <unistd.h>
#include <stdio.h>
int main() {
	char b;

	while (1) {
		int r = read(0, &b, 1);
		printf("{%c\t|%d\t|%d}\n", b, b, r);
	}
	return (0);
}
