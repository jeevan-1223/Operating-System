#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int blockNumber;
    struct Block* next;
} Block;

typedef struct File {
    Block* head;
    Block* tail;
} File;

File* createFile() {
    File* file = (File*)malloc(sizeof(File));
    file->head = file->tail = NULL;
    return file;
}

void addBlock(File* file, int blockNumber) {
    Block* newBlock = (Block*)malloc(sizeof(Block));
    newBlock->blockNumber = blockNumber;
    newBlock->next = NULL;
    if (!file->head) {
        file->head = file->tail = newBlock;
    } else {
        file->tail->next = newBlock;
        file->tail = newBlock;
    }
}

void displayFile(File* file) {
    Block* current = file->head;
    while (current) {
        printf("Block %d -> ", current->blockNumber);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    File* myFile = createFile();
    addBlock(myFile, 1);
    addBlock(myFile, 2);
    addBlock(myFile, 3);
    displayFile(myFile);
    return 0;
}

