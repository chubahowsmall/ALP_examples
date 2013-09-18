#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	pid_t child_pid;
	pid_t parent_pid;

	child_pid = getpid();
	parent_pid = getppid();

	printf("PID is %d\n", child_pid);
	printf("PPID is %d\n", parent_pid);

	return 0;
}
