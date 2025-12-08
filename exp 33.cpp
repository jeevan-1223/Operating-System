#include <stdio.h>

#define MAX_RECORDS 100

void readRecords(char records[MAX_RECORDS][100], int count) {
    for (int i = 0; i < count; i++) {
        printf("Record %d: %s\n", i + 1, records[i]);
    }
}

int main() {
    char records[MAX_RECORDS][100] = {
        "Record 1: Data A",
        "Record 2: Data B",
        "Record 3: Data C"
    };
    int count = 3;

    readRecords(records, count);
    return 0;
}

