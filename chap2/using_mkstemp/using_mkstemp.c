#include <stdio.h>
#include <unistd.h>
#include "using_mkstemp.h"

/*
Desc:
	create a temp file and write "buffer" to it with "length" bytes
	
Param:
	char *buffer - the stuff to be written to the file
	size_t length - the size of the buffer to be written	

Return value:
	int - the fd of the temporary file
*/

int write_temp_file(char *buffer, size_t length)
{
	int fd = 0;

	char temp_file[] = "/tmp/tmp_file.XXXXXX";

	fd = mkstemp(temp_file);

	printf("Try to write %d bytes to %s\n", length, temp_file);

	/* call unlink() immediately, so that it will be removed
		when the file is no more used. (file reference count is zero)
	*/
	unlink(temp_file);

	/* write the size first */
	write(fd, &length, sizeof(size_t));

	/* write data */
	write(fd, buffer, length);

	printf("Writing file is done.\n");

	/* return the fd to caller */
	return fd;
}

/*
Desc:
	read back the stored data of temporary file

Params:
	int fd - the file descriptor of the temporary file
	size_t length - the size to be read

Return value:
	char * - the NUL-terminated character string
*/
char *read_temp_file(int fd, size_t *length)
{
	char *buffer = NULL;

	/* rewind to the beginning of the temporary file */
	lseek(fd, 0, SEEK_SET);

	/* read the size of the data in the temporary file */
	read(fd, length, sizeof(size_t));
	printf("length is %d\n", *length);

	/* allocating memory buffer to store the data */
	buffer = (char *) malloc(*length * sizeof(char));
	
	/* read the data in temporary file */
	read(fd, buffer, *length);


	/* close the temporary file */
	close(fd);

	return buffer;
}
