#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char filename[] = "hello.txt";
	int fd = syscall(__NR_open, filename, O_RDWR|O_CREAT, 0777);
	close(fd);
	exit(EXIT_SUCCESS);
}
