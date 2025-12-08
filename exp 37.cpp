#include <stdio.h>
#include <stdlib.h>

void scan(int arr[], int size, int head, int direction) {
    // Similar implementation as above
    // Sorting, seek sequence calculation, and total seek time calculation
    // Omitted for brevity
}

int main() {
    int size;
    printf("Enter the number of requests: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the requests: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int head;
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    int direction;
    printf("Enter direction (1 for right, 0 for left): ");
    scanf("%d", &direction);

    scan(arr, size, head, direction);
    return 0;
}

