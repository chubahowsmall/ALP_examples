#ifndef __USING_MKSTEMP_H
#define __USING_MKSTEMP_H


int write_temp_file(char *buffer, size_t length);
char *read_temp_file(int fd, size_t *length);

#endif
