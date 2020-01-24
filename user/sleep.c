#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char* argv[]) {
	int time;
	if (argc <= 1) {
		printf("sleep: time not specified\n");
		exit();
	}

	if (argc > 2) {
		printf("sleep: too many arguments\n");
		exit();
	}
	time = atoi(argv[1]);
	sleep(time);
	exit();
}
