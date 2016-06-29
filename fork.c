#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int pid, status;

	if ((pid = fork()) == 0) {
		printf("in child: pid is %d, parent pid is %d\n",
		       getpid(), getppid());
		exit(0);
	}
	else {
		printf("in parent: pid is %d, child pid is %d\n",
		       getpid(), pid);
		pid = wait(&status);
		printf("child pid %d exited with status %d\n", pid, status);
	}
}
