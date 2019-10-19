#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


int main()
{
    Stack_t ST1;
    Create_Stack(&ST1 , 10);

    for(uint8_t i = 0; i < ST1.Size ; i++)
    {
        Stack_Push(&ST1 , i);
    }

    for(uint8_t i = 0; i < ST1.Size ; i++)
    {
        printf("%d" , Stack_Pop(&ST1));
    }

    return 0;
}
