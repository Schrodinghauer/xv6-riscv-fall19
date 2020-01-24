#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char* argv[]) {
	int pid, n;
	int parent_fd[2], child_fd[2];
	char buf[100];
	pipe(parent_fd);
	pipe(child_fd);
	write(parent_fd[1], "4: received ping\n", 17);
	pid = fork();
	// The following code will be executed in
	// both parent proc and child proc.
	if (pid == 0) {
		// in child process
		n = read(parent_fd[0], buf, sizeof(buf));
		write(1, buf, n);
		write(child_fd[1], "3: received pong\n", 17);
	}

	else if (pid > 0) {
		// in parent process
		n = read(child_fd[0], buf, sizeof(buf));
		write(1, buf, n);
	}

	else {
		// there's an error
		printf("An error has occurred.\n");
		exit();
	}

	// printf("fd[0]: %d, fd[1]: %d\n", fds[0], fds[1]);
	exit();
}
