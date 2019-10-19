

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdint.h>

typedef struct Queue{
    uint8_t *arr;
    uint8_t Size;
    uint8_t Front;
    uint8_t Rear;
    uint8_t Numb_of_elements;

}ST_queueInfo;


void createQueue(ST_queueInfo* info, uint8_t maxSize);
void enqueue(ST_queueInfo *info, uint8_t data);
void dequeue(ST_queueInfo *info, uint8_t* data);


#endif // QUEUE_H_
