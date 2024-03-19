#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define NO 0
#define YES 1

int main() {
    char c;
    int fd; // file descriptor
    char filename[20];
    char filecontent[256];
    int choice = YES;
    
    
    if (choice == YES) {
        printf("Enter the name of the file to be created: \n");
        gets(filename); // Using gets() to read the filename
        printf("Write the content of the file: \n");
        gets(filecontent); 
		fd = open(filename, O_CREAT | O_WRONLY, 0644);
    }
    
    else {
        printf("Enter the name of the file to be read: ");
		gets(filename); // Using gets() to read the filename
        fd = open(filename, O_RDONLY);
		while (read(fd, &c, 1) != 0) {
				write(STDOUT_FILENO, &c, 1);
			}
		}
    close(fd); // Close the file descriptor
    return 0;
}
