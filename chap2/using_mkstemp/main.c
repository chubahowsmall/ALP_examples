#include <stdio.h>
#include "using_mkstemp.h"

int main(int argc, char *argv[])
{
	int temp_fd = (-1);
	char msg[] = "Stay hungry, stay foolish.";
	char *readBack = NULL;
	int length = sizeof(msg);

	printf("length of msg is %d\n", length);

	temp_fd = write_temp_file(msg, 
						length+1/* don't forget the "\0" character */);	

	/* Read back data */
	readBack = read_temp_file(temp_fd, &length);
	printf("%s(): read length = %d\n", __func__, length);
	printf("%s(): msg is %s\n", __func__, readBack);

	free(readBack);



	return 0;
}

