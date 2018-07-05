#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int pid, status;

	if ((pid = fork()) == 0) {
		/* fork returns 0 in child */
		printf("in child: pid is %d, parent pid is %d\n",
		       getpid(), getppid());
		exit(0);
	}
	else {
		/* fork returns pid to parent */
		printf("in parent: pid is %d, child pid is %d\n",
		       getpid(), pid);
		pid = wait(&status);
		printf("child pid %d exited with status %d\n", pid, status);
	}
}
