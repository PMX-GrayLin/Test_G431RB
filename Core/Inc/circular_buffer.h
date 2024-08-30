#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h> // for size_t

#define SIZE_RING 10

typedef struct {
    float data[SIZE_RING];
    size_t head;
    size_t count;
    float sum;
} CircularBuffer;

void initBuffer(CircularBuffer *cb);
void addData(CircularBuffer *cb, float newValue);
double getAverage(const CircularBuffer *cb);

#endif // CIRCULAR_BUFFER_H
