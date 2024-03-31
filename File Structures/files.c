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
    int choice;

    printf("Do you want to create a new file (1) or read an existing file (0)? ");
    scanf("%d", &choice);
    getchar(); // Consume the newline character left in the input buffer

    if (choice == YES) {
        printf("Enter the name of the file to be created: \n");
        fgets(filename, sizeof(filename), stdin); // Using fgets() for input
        strtok(filename, "\n"); // Remove the trailing newline if present
        printf("Write the content of the file: \n");
        fgets(filecontent, sizeof(filecontent), stdin);
        strtok(filecontent, "\n");
        fd = open(filename, O_CREAT | O_WRONLY, 0644);
        if (fd == -1) {
            perror("Failed to create file");
            return 1;
        }
        write(fd, filecontent, strlen(filecontent));
    } else if (choice == NO) {
        printf("Enter the name of the file to be read: ");
        fgets(filename, sizeof(filename), stdin);
        strtok(filename, "\n");
        fd = open(filename, O_RDONLY);
        if (fd == -1) {
            perror("Failed to open file");
            return 1;
        }
        while (read(fd, &c, 1) != 0) {
            write(STDOUT_FILENO, &c, 1);
        }
		printf("\n");
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    close(fd); // Close the file descriptor
    return 0;
}

