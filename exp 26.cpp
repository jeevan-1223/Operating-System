#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "Hello, File Management!\n");
        fclose(file);
    }
}

void readFile(const char *filename) {
    char buffer[100];
    FILE *file = fopen(filename, "r");
    if (file) {
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
    }
}

void deleteFile(const char *filename) {
    remove(filename);
}

int main() {
    const char *filename = "example.txt";
    createFile(filename);
    readFile(filename);
    deleteFile(filename);
    return 0;
}

