
#ifndef STACK_H_
#define STACK_H_

#include <stdint.h>

typedef struct Stack{
    uint8_t Size;
    uint8_t top;
    uint8_t *arr;

}Stack_t;


void Create_Stack(Stack_t *ST , uint8_t Size);
int8_t Stack_Push( Stack_t *ST , uint8_t data );
uint8_t Stack_Pop( Stack_t *ST );


#endif // STACK_H_
