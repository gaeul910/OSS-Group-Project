#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 256

typedef struct Stack
{
    double data[256];
    int topindex;
} Stack;

int check_operator(char input)
{
    switch (input)
    {
    case '+':
        return 1;
    case '-':
        return 2;
    case '/':
        return 3;
    case '*':
        return 4;
    }
}

double pop(Stack *stack)
{
    if (stack->topindex > -1)
    {
        return stack->data[stack->topindex--];
    }
    else
    {
        printf("Stack is Empty");
        return -1;
    }
}
int push(double newdata, Stack *stack)
{
    if (stack->topindex <= MAXDATA - 1)
    {
        stack->data[++stack->topindex] = newdata;
        return 0;
    }
    else
    {
        printf("Stack is Full!");
        return -1;
    }
}

Stack *init()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->topindex = -1;

    return stack;
}

int main()
{
    printf(">>> ");
    char input[MAXDATA];
    gets(input);
    double temp = 0;
    int num1 = 0;
    int num2 = 0;

    Stack *stack = init();

    for (int i = 0; input[i] != 0; i++) // input[i]가 \0이 아닐 동안
    {
        if (input[i] == 32)
            continue;
        if (input[i] >= '0' && input[i] <= '9') // 입력값이 피연산자일 경우
        {
            temp = 0;
            while (input[i] != 32)
            {
                temp *= 10;
                temp += input[i] - '0';
                i++;
            }
            push(temp, stack);
        }

        else
        {
            num1 = pop(stack);
            num2 = pop(stack);
            switch (check_operator(input[i]))
            {
            case 1:
                push(num2 + num1, stack);
                break;
            case 2:
                push(num2 - num1, stack);
                break;
            case 3:
                push(num2 / num1, stack);
                break;
            case 4:
                push(num2 * num1, stack);
                break;
            default:
                printf("Error: Unexpected value");
                break;
            }
        }
    }

    printf("%lf", pop(stack));
}
