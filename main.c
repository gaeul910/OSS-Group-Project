#include <stdio.h>
#define MAXDATA 256

typedef struct Stack
{
    double data[256];
    int topindex;
} Stack;

Stack *init()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    return stack;
}

int stackPush(int newdata, Stack *stack)
{
    if (stack->topindex < MAXDATA)
    {
        stack->data[++stack->topindex] = newdata;
        return 0;
    }
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
        if (input[i] >= '0' && input[i] <= '9')
        {
            for (int j = 1; input[i] != ' '; j *= 10)
            {
                temp += input[i] - '0';
                temp *= j;
            }
            stackPush(temp, stack);
        }
    }
}