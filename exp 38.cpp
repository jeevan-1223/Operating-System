#include <stdio.h>

void cscan(int arr[], int size, int head, int disk_size) {
    int seek_sequence[size + 1], index = 0, distance, total_seek = 0;
    
    // Sort the request array
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    // Service requests in one direction
    for (int i = 0; i < size; i++) {
        if (arr[i] >= head) {
            seek_sequence[index++] = head;
            distance = arr[i] - head;
            total_seek += distance;
            head = arr[i];
        }
    }
    
    // Jump to the start of the disk
    total_seek += (disk_size - 1 - head);
    head = 0;
    seek_sequence[index++] = head;

    // Service remaining requests
    for (int i = 0; i < size; i++) {
        if (arr[i] < head) {
            seek_sequence[index++] = head;
            distance = arr[i] - head;
            total_seek += distance;
            head = arr[i];
        }
    }

    printf("Total Seek Time: %d\n", total_seek);
    printf("Seek Sequence: ");
    for (int i = 0; i < index; i++)
        printf("%d ", seek_sequence[i]);
}

int main() {
    int requests[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int size = sizeof(requests) / sizeof(requests[0]);
    int head = 50, disk_size = 200;

    cscan(requests, size, head, disk_size);
    return 0;
}

