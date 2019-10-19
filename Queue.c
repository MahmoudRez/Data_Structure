

#include "Queue.h"

void createQueue(ST_queueInfo *info, uint8_t maxSize)
{
    info->arr = (uint8_t*)malloc(sizeof(uint8_t) * maxSize);
    info->Size = maxSize;
    info->Front = 0;
    info->Rear = 0;
    info->Numb_of_elements = 0;
}


void enqueue(ST_queueInfo *info, uint8_t data)
{
    /*if( ( (info->Rear + 1) % info->Size) == info->Front )*/
    if(info->Numb_of_elements == info->Size)
    {
        return;
    }
    info->arr[info->Rear] = data;
    info->Rear = (info->Rear + 1) % info->Size;
    info->Numb_of_elements++;
}

void dequeue(ST_queueInfo *info, uint8_t *data)
{
    /*if( info->Front == info->Rear )*/
    if(info->Numb_of_elements == 0)
    {
        return;
    }
    *data = info->arr[info->Front];
    info->Front = (info->Front + 1 ) % info->Size;
    info->Numb_of_elements--;

}


