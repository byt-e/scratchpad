#include <unistd.h>

int main() {
	const char *msg = "Hello from write()\n";
	write(1, msg, 20); // fd 1 = stdout
	return 0;
}
