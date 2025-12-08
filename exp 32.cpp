#include <stdio.h>
#include <stdlib.h>

#define FRAME_SIZE 3
#define PAGE_SIZE 10

int pages[PAGE_SIZE] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
int frames[FRAME_SIZE], lastUsed[FRAME_SIZE];
int pageFaults = 0;

void lru() {
    for (int i = 0; i < PAGE_SIZE; i++) {
        int j, found = 0;
        for (j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                lastUsed[j] = i; // Update last used time
                break;
            }
        }
        if (!found) {
            int lruIndex = 0;
            for (j = 1; j < FRAME_SIZE; j++)
                if (lastUsed[j] < lastUsed[lruIndex]) lruIndex = j;
            frames[lruIndex] = pages[i];
            lastUsed[lruIndex] = i; // Update last used time
            pageFaults++;
        }
    }
}

int main() {
    for (int i = 0; i < FRAME_SIZE; i++) frames[i] = -1; // Initialize frames
    lru();
    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}

