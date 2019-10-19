#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

unsigned char checkForBalancedParantheses(unsigned char *str);
long long evaluate(char* expression);

int main()
{

    long long Result = 0;
    unsigned char *str = "(5+5)*(5-2)";
    Result =  evaluate(str);

    printf("\nExpression result = %lld\n" , Result);
    return 0;
}


long long evaluate(char* expression)
{
    ST_queueInfo Q1;
    ST_queueInfo Q2;
    long long temp = 0;
    uint8_t operand = 0;
    uint8_t second_operator = 0;
    //Stack ST1;
    uint8_t str_size = 0;
    while(expression[str_size] != 0)
    {
        str_size++;
    }
    createQueue(&Q1 , str_size);
    createQueue(&Q2 , str_size);
    //Create_Stack(&ST1,str_size);

    if(checkForBalancedParantheses(expression) == 'B')
    {

        for( uint8_t i = 0 ; i < str_size ; i++)
        {
            if( ( (expression[i] >= 49) && (expression[i] <= 57) ) )
            {
                enqueue(&Q1 , expression[i] - '0');
            }
            else if( (expression[i]=='+') || (expression[i]=='/') || (expression[i]=='*') || (expression[i]=='-') )
            {
                enqueue(&Q1 , expression[i]);
            }
           else if( (expression[i]=='{') || (expression[i]=='[') || (expression[i]=='(') || (expression[i]=='}') || (expression[i]==']') || (expression[i]==')') ){}
            else
            {
                printf("Invalid expression");
                return;
            }
        }
        uint8_t j = 1;
        for(uint8_t i = 0 ; i < Q1.Numb_of_elements - 1 ; i+=2)
        {
            if( (Q1.arr[i] >= 1) && (Q1.arr[i] <= 9) ){}
            else
            {
                printf("Invalid operation");
                return;
            }
            if( (Q1.arr[j] == '+' ) || (Q1.arr[j] == '-' ) || (Q1.arr[j] == '/' ) || (Q1.arr[j] == '*' ) ){}
            else
            {
                printf("\nInvalid operation");
                return;
            }
            j+=2;
        }


      dequeue(&Q1 , &temp);
     // printf("%d",temp);

      while(Q1.Numb_of_elements > 0)
      {
        dequeue(&Q1 , &operand);
        switch(operand)
          {
        case '+':
            dequeue(&Q1 , &second_operator);
            temp = temp + second_operator;
            break;
        case '-':
            dequeue(&Q1 , &second_operator);
            temp = temp - second_operator;
            break;
        case '*':
            dequeue(&Q1 , &second_operator);
            temp = temp * second_operator;
            break;
        case '/':
            dequeue(&Q1 , &second_operator);
            temp = temp / second_operator;
            break;
          }
      }

    }
    else
    {
       printf("Expression not balanced");
       return;
    }

    return temp;

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
