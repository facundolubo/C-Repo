#include <stdio.h>
#include <fcntl.h>

int main () {
	char c;
	int fd; // file descriptor
	char filename[20];
	printf("Enter the name of the file: ");
	gets(filename);
	fd = open(filename, O_RDONLY);
	while (read(fd, &c, 1) != 0) {
		write(STDOUT, &c, 1);
	};
	close(fd);
	return 0;
}
