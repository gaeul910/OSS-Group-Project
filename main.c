#include <stdio.h>
#define MAXDATA 256

typedef struct Stack
{
    double data[256];
    int topindex;
} Stack;

int push(double data, Stack *stack)
{
    if (stack->topindex <= MAXDATA - 1)
    {
        stack->data[++stack->topindex] = data;
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
    return stack;
}

int main()
{
    printf(">>> ");
    char input[MAXDATA];
    gets(input);
    double temp = 1;

    Stack *stack = init();

    for (int i = 0; input[i] != 0; i++) // input[i]가 \0이 아닐 동안
    {
        if (input[i] == 32)
            continue;
        if (input[i] >= '0' && input[i] <= '9') // 입력값이 피연산자일 경우
        {
            for (int j = 1; input[i] != ' '; j *= 10)
            {
                temp += input[i] - '0';
                temp *= j;
            }
            push(temp, stack);
        }
    }
}
