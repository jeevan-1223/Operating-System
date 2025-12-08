#include <stdio.h>
#include <sys/stat.h>

void printPermissions(mode_t mode) {
    printf( (S_ISDIR(mode)) ? "d" : "-");
    printf( (mode & S_IRUSR) ? "r" : "-");
    printf( (mode & S_IWUSR) ? "w" : "-");
    printf( (mode & S_IXUSR) ? "x" : "-");
    printf( (mode & S_IRGRP) ? "r" : "-");
    printf( (mode & S_IWGRP) ? "w" : "-");
    printf( (mode & S_IXGRP) ? "x" : "-");
    printf( (mode & S_IROTH) ? "r" : "-");
    printf( (mode & S_IWOTH) ? "w" : "-");
    printf( (mode & S_IXOTH) ? "x" : "-");
}

int main() {
    struct stat fileStat;
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    if (stat(filename, &fileStat) < 0) {
        printf("Error reading file.\n");
        return 1;
    }

    printf("File Permissions: ");
    printPermissions(fileStat.st_mode);

    printf("\n\nUser Types:\n");
    printf("Owner (u)\n");
    printf("Group (g)\n");
    printf("Others (o)\n");

    return 0;
}

