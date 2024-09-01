#include "ex_can.h"
#include "global.h"

CANFIFOBuffer canFIFO = { 0 };

// Add an element to the FIFO buffer
bool CANFIFO_enqueue(CANTxData data) {
  if (CANFIFO_full()) {
    xlog("%s:%d CAN FIFO Buffer Full\n\r", __func__, __LINE__);
    return false;
  }

  canFIFO.data[canFIFO.tail] = data;                    // Add value to the buffer
  canFIFO.tail = (canFIFO.tail + 1) % CAN_BUFFER_SIZE;  // Increment tail index circularly
  canFIFO.count++;                                      // Increase the count of elements

  return true;
}

// Remove an element from the FIFO buffer
bool CANFIFO_dequeue(CANTxData* canTxData) {
  if (CANFIFO_empty()) {
    xlog("%s:%d CAN FIFO Buffer Empty\n\r", __func__, __LINE__);
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

bool CANFIFO_full() {
  return canFIFO.count == CAN_BUFFER_SIZE;
}

