#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main()
{
    ST_queueInfo Q1;

    createQueue(&Q1 , 20);

   /* for(uint8_t i = 0 ; i < 10 ; i++)
    {
        enqueue(&Q1 , i);
    }
    uint8_t data;

    for(uint8_t i = 0 ; i < 10 ; i++)
    {
        dequeue(&Q1 , &data);
        printf("%d\t", data);
    }*/
    uint8_t data;
    enqueue(&Q1 , 10);
    enqueue(&Q1 , 20);
    enqueue(&Q1 , 33);
    enqueue(&Q1 , 11);

    uint8_t N = Q1.Numb_of_elements;
    for( uint8_t i = 0 ; i < N ; i++)
    {
       // printf("%d\t",Q1.Numb_of_elements);
        dequeue(&Q1 , &data);
        printf("%d\t",data);
    }

    return 0;
}
