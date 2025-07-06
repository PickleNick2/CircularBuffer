#include "circbuff.h"
#include <string.h>

void circbuff_init(CircularBuffer *circbuff){
	circbuff->head = 0;
	circbuff->tail = 0;
	circbuff->full = false;
	memset(circbuff->buffer, 0, CIRCBUFF_SIZE);
}


bool circbuff_is_empty(CircularBuffer *circbuff){
	bool isEmpty = (circbuff->head == circbuff->tail) && !circbuff->full;
	return isEmpty;
}

bool circbuff_is_full(CircularBuffer *circbuff){
	return circbuff->full;
}


bool circbuff_write(CircularBuffer *circbuff, uint8_t data){
	if (circbuff->full){
		return false; //Buffer overflow
	}

	circbuff->buffer[circbuff->head] = data;
	circbuff->head = (circbuff->head + 1) % CIRCBUFF_SIZE;

	if (circbuff->head == circbuff->tail){
		circbuff->full = true;
	}
	return true;
}

bool circbuff_read(CircularBuffer *circbuff, uint8_t *data){
	if (circbuff_is_empty(circbuff)){
		return false;
	}

	*data = circbuff->buffer[circbuff->tail];
	circbuff->tail = (circbuff->tail + 1) % CIRCBUFF_SIZE;
	circbuff->full = false;

	return true;
}


bool circbuff_peek(CircularBuffer *circbuff, uint8_t *data){
	if (circbuff_is_empty(circbuff)){
		return false;
	}
	*data = circbuff->buffer[circbuff->tail];
	return true;
}

void circbuff_clear(CircularBuffer *circbuff){
	circbuff->head = circbuff->tail = 0;
	circbuff->full = false;
}
