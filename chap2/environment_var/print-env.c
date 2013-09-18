#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[])
{
	char **var;
	char *env = NULL;

	for(var = environ; *var != NULL; ++var)
	{
		printf("%s\n", *var);
	}
	
	printf("Get PATH:\n");
	env = getenv("PATH");
	if(env != NULL)
	{
		printf("PATH = %s\n", env);
	}
	else
	{
		printf("PATH is not defined\n");
	}

	return 0;
}
