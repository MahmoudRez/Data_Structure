#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

unsigned char checkForBalancedParantheses(unsigned char* expression);


int main()
{
   unsigned char *str = "({[{}[]})";
    if(checkForBalancedParantheses(str) == 'B')
    {
        printf("BALANCED !!!");
    }
    else
    {
        printf("UNBALANCED");
    }
    return 0;
}




unsigned char checkForBalancedParantheses(unsigned char *str)
{
    uint8_t str_size = 0;
    uint8_t return_now = 0;
    while(str[str_size] != 0)
    {
        str_size++;
    }

    Stack_t ST1;
    Create_Stack(&ST1 , str_size );

    for(uint8_t i = 0 ; i < str_size ; i++)
    {
        if( (str[i] == '(' ) || (str[i] == '{') || (str[i] == '[') )
        {
            Stack_Push(&ST1 , str[i]);
        }
        else if( (str[i] == ')' ) || (str[i] == '}') || (str[i] == ']') )
        {
            return_now = 0;
            switch(str[i])
            {
            case ')':
                for(uint8_t j = 0; j < i ; j++)
                {
                    if(str[j] == '('){return_now |= 1;}
                }
                if( ST1.arr[ST1.top -1] == '(' )
                {
                    Stack_Pop(&ST1);
                }
                break;
            case ']':
                for(uint8_t j = 0; j < i ; j++)
                {
                    if(str[j] == '['){return_now |= 1;}
                }
                if(ST1.arr[ST1.top -1] == '[')
                {
                    Stack_Pop(&ST1);
                }
                break;

            case '}':
                for(uint8_t j = 0; j < i ; j++)
                {
                    if(str[j] == '{'){return_now |= 1;}
                }
                if(ST1.arr[ST1.top -1] == '{')
                {
                    Stack_Pop(&ST1);
                }
                break;
            }

            if(return_now == 0)
            {
                return 'U';
            }
        }
    }
    if(ST1.top == 0)
    {
        return 'B';
    }
    else
    {
        return 'U';
    }
}
