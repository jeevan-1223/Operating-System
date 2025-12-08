#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 10

typedef struct {
    int blockNumber;
    char data[256];
} FileBlock;

typedef struct {
    FileBlock *blocks[MAX_BLOCKS];
} IndexBlock;

void allocateFile(IndexBlock *index) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        index->blocks[i] = (FileBlock *)malloc(sizeof(FileBlock));
        index->blocks[i]->blockNumber = i;
        snprintf(index->blocks[i]->data, sizeof(index->blocks[i]->data), "Data for block %d", i);
    }
}

void displayFile(IndexBlock *index) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        printf("Block %d: %s\n", index->blocks[i]->blockNumber, index->blocks[i]->data);
    }
}

int main() {
    IndexBlock index;
    allocateFile(&index);
    displayFile(&index);

    // Free allocated memory
    for (int i = 0; i < MAX_BLOCKS; i++) {
        free(index.blocks[i]);
    }

    return 0;
}

