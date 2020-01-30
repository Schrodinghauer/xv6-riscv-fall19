#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int buf[40];

int prime_pipe(int size) {
	int count = 0;
	int div = buf[0];
	printf("prime %d\n", div);
	for (int i = 0; i < size; ++i) {
		if (!(buf[i] % div)) {
			continue;
		}
		else {
			buf[count] = buf[i];
			count++;
		}
	}
	return count;
}

int main(int argc, char* argv[]) {
	int pid;
	int parent_fd[2];
	pipe(parent_fd);
	for (int i = 2; i < 35; ++i) {
		buf[i] = i;
	}

	int size = prime_pipe(40);

	write(parent_fd[1], &size, sizeof(int));
	pid = fork();
	printf("pid: %d\n", pid);

	while (size >= 1) {
		size = prime_pipe(size);
	}
	exit();
}