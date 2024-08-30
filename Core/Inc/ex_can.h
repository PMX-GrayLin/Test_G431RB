#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define CAN_BUFFER_SIZE 8

typedef struct {
  uint32_t id;
  uint8_t data[8];
} CANTxData;

typedef struct {
  CANTxData data[CAN_BUFFER_SIZE];  // Buffer storage
  int head;                            // Index for the next read
  int tail;                            // Index for the next write
  int count;                           // Number of elements currently in the buffer
} CANFIFOBuffer;

void CANFIFO_init();
bool CANFIFO_enqueue(CANTxData data);
bool CANFIFO_dequeue(CANTxData *data);
bool CANFIFO_empty();
