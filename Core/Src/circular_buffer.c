#include "circular_buffer.h"

void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->count = 0;
    cb->sum = 0;
    for (size_t i = 0; i < SIZE_RING; i++) {
        cb->data[i] = 0;
    }
}

void addData(CircularBuffer *cb, float newValue) {
    // If the buffer is full, subtract the value that is being overwritten from the sum
    if (cb->count == SIZE_RING) {
        cb->sum -= cb->data[cb->head];
    } else {
        cb->count++;
    }

    // Add the new value to the buffer
    cb->data[cb->head] = newValue;

    // Add the new value to the sum
    cb->sum += newValue;

    // Move the head pointer
    cb->head = (cb->head + 1) % SIZE_RING;
}

double getAverage(const CircularBuffer *cb) {
    if (cb->count == 0) {
        return 0.0; // Avoid division by zero
    }
    return (double)cb->sum / cb->count;
}
