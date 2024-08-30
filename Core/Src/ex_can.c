#include "ex_can.h"

CANFIFOBuffer canFIFO = { 0 };

// Initialize the FIFO buffer
void CANFIFO_init() {
  canFIFO.head = 0;
  canFIFO.tail = 0;
  canFIFO.count = 0;
}

// Add an element to the FIFO buffer
bool CANFIFO_enqueue(CANTxData data) {
  if (canFIFO.count == CAN_BUFFER_SIZE) {
    return false;  // Buffer is full
  }

  canFIFO.data[canFIFO.tail] = data;                    // Add value to the buffer
  canFIFO.tail = (canFIFO.tail + 1) % CAN_BUFFER_SIZE;  // Increment tail index circularly
  canFIFO.count++;                                      // Increase the count of elements
  return true;
}

// Remove an element from the FIFO buffer
bool CANFIFO_dequeue(CANTxData* canTxData) {
  if (canFIFO.count == 0) {
    // Buffer is empty
    return false;
  }

  *canTxData = canFIFO.data[canFIFO.head];              // Retrieve the value from the buffer
  canFIFO.head = (canFIFO.head + 1) % CAN_BUFFER_SIZE;  // Increment head index circularly
  canFIFO.count--;                                      // Decrease the count of elements
  return true;
}

bool CANFIFO_empty() {
  return canFIFO.count == 0;
}
