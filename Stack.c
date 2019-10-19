

#include "Stack.h"

void Create_Stack(Stack_t *ST , uint8_t Size)
{
    ST->arr = (uint8_t*)malloc(sizeof(uint8_t) * Size);
    ST->Size = Size;
    ST->top = 0;
}

int8_t Stack_Push( Stack_t *ST , uint8_t data )
{
    if( ST->top == ST->Size )
    {
        return -1;
    }
    ST->arr[ST->top] = data;
    ST->top++;
    return 0;
}

uint8_t Stack_Pop( Stack_t *ST )
{
    if(ST->top == 0)
    {
        return;
    }
    ST->top--;
    uint8_t temp = ST->arr[ST->top];
    return temp;

}

