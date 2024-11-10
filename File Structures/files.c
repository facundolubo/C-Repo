/* PARAMETERS:
 * -r for read file
 * -w for write a file
 *  filename (optional) after parameter
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define NO 0
#define YES 1

void main(int argc, char *argv[]) {
    char c;
    int fd; // file descriptor
    int choice = -1; // Initialize to avoid undefined behavior
    char param;
    char filename[20] = ""; // Initialize filename to empty
    char filecontent[256];

    if (argc > 1) {
        while (argc-- > 0 && (*++argv)[0] == '-') {
            while ((param = *++argv[0])) {
                switch(param) {
                    case 'r':
                        choice = 0;
                        break;
                    case 'w':
                        choice = 1;
                        break;
                    default:
                        printf("Invalid option, only -r for read and -w for write\n");
                        return 1;
                }
            }
        }
        if (*argv != NULL) {
            strncpy(filename, *argv, sizeof(filename) - 1);
            filename[sizeof(filename) - 1] = '\0';
            printf("File to read/write: %s\n", filename);
        }
    } else {
        printf("Do you want to create a new file (1) or read an existing file (0)? ");
        scanf("%d", &choice);
        getchar(); // Consume the newline left by scanf
    }

    if (choice == YES) {
        if (filename[0] == '\0') {  // Check if filename is empty
            printf("Enter the name of the file to be created: ");
            fgets(filename, sizeof(filename), stdin);
            strtok(filename, "\n");
        }
        printf("Write the content of the file: ");
        fgets(filecontent, sizeof(filecontent), stdin);
        strtok(filecontent, "\n");

        fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644); // Use O_TRUNC to clear any existing content
        if (fd == -1) {
            perror("Failed to create file");
            return 1;
        }
        write(fd, filecontent, strlen(filecontent));
        close(fd); // Close the file descriptor after writing
    } else if (choice == NO) {
        if (filename[0] == '\0') {
            printf("Enter the name of the file to be read: ");
            fgets(filename, sizeof(filename), stdin);
            strtok(filename, "\n");
        }

        fd = open(filename, O_RDONLY);
        if (fd == -1) {
            perror("Failed to open file");
            return 1;
        }
        while (read(fd, &c, 1) > 0) {
            write(STDOUT_FILENO, &c, 1);
        }
        close(fd); // Close the file descriptor after reading
    } else {
        printf("Invalid choice\n");
        return 1;
    }
}

