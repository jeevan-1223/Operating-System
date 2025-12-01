#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 1024  
int main() 
{
    int src_fd, dest_fd;
    char buffer[BUF_SIZE];
    ssize_t bytesRead;
    src_fd = open("source.txt", O_RDONLY);
    if (src_fd < 0) 
	{
        perror("Error opening source file");
        exit(1);
    }
    dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) 
	{
        perror("Error opening destination file");
        close(src_fd);
        exit(1);
    }
    while ((bytesRead = read(src_fd, buffer, BUF_SIZE)) > 0) 
	{
        if (write(dest_fd, buffer, bytesRead) != bytesRead) 
		{
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            exit(1);
        }
    }
    if (bytesRead < 0) {
        perror("Error reading source file");
    }
    close(src_fd);
    close(dest_fd);
    printf("File copied successfully!\n");
    return 0;
}

