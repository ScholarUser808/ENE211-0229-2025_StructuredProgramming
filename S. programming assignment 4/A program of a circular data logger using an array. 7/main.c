#include <stdio.h>

#define BUFFER_SIZE 10

typedef struct {
    int data[BUFFER_SIZE];
    int head;   /* Index where the next value will be written */
    int count;  /* Number of valid elements currently stored (0..BUFFER_SIZE) */
} CircularBuffer;

void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->count = 0;
}

void insertSample(CircularBuffer *cb, int value) {
    cb->data[cb->head] = value;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    if (cb->count < BUFFER_SIZE) {
        cb->count++;
    }
}

void printBufferRaw(const CircularBuffer *cb) {
    printf("Buffer [ ");
    for (int i = 0; i < cb->count; i++) {
        printf("%d ", cb->data[i]);
    }
    printf("]\n");
}

void printChronological(const CircularBuffer *cb) {
    if (cb->count == 0) {
        printf("Buffer is empty.\n");
        return;
    }

    int start = (cb->count < BUFFER_SIZE) ? 0 : cb->head;
    printf("Chronological (oldest -> newest): ");
    for (int i = 0; i < cb->count; i++) {
        int idx = (start + i) % BUFFER_SIZE;
        printf("%d%s", cb->data[idx], (i < cb->count - 1) ? " " : "\n");
    }
}

int main(void) {
    CircularBuffer cb;
    initBuffer(&cb);

    int value;
    printf("Circular data logger (BUFFER_SIZE = %d)\n", BUFFER_SIZE);
    printf("Enter up to %d values (enter 'q' or Ctrl+D to stop):\n", BUFFER_SIZE);

    /* Fill up to the 10th value */
    while (cb.count < BUFFER_SIZE) {
        printf("Value %d: ", cb.count + 1);
        if (scanf("%d", &value) != 1) {
            printf("Input stopped.\n");
            printBufferRaw(&cb);
            printChronological(&cb);
            return 0;
        }
        insertSample(&cb, value);
    }

    /* Display buffer after 10th value is entered */
    printf("\nBuffer full (10 values entered):\n");
    printBufferRaw(&cb);
    printChronological(&cb);

    /* For each additional value, update buffer and display contents */
    printf("\nEnter additional values to overwrite oldest (enter 'q' or Ctrl+D to stop):\n");
    while (scanf("%d", &value) == 1) {
        insertSample(&cb, value);
        printBufferRaw(&cb);
        printChronological(&cb);
    }

    printf("\nStopped entering data. Final buffer state:\n");
    printBufferRaw(&cb);
    printChronological(&cb);

    return 0;
}
