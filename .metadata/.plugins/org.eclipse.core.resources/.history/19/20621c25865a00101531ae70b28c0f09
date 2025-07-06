#ifndef INC_CIRCBUFF_H_
#define INC_CIRCBUFF_H_

#include <stdint.h>
#include <stdbool.h>

//Predefined size of buffer
#define CIRCBUFF_SIZE 64

typedef struct {
	uint8_t buffer[CIRCBUFF_SIZE];
	uint16_t head;
	uint16_t tail;
	bool full;

} CircularBuffer;

//Function to initialize the buffer
void circbuff_init(CircularBuffer *circbuff);

//Function to check if circular buffer is empty
bool circbuff_is_empty(CircularBuffer *circbuff);

//Function to check if circular buffer is full
bool circbuff_is_full(CircularBuffer *circbuff);

//Function to write byte to circular buffer
bool circbuff_write(CircularBuffer *circbuff, uint8_t data);

//Function to read a byte from the buffer
bool circbuff_read(CircularBuffer *circbuff, uint8_t *data);

//Function to peek at the next byte without removing it
bool circbuff_peek(CircularBuffer *circbuff, uint8_t *data);

//Empty the buffer
void circbuff_clear(CircularBuffer *circbuff);

#endif /* INC_CIRCBUFF_H_ */
