#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    char postfix[MAX];
    int i;
    int operand1, operand2, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            operand2 = pop();
            operand1 = pop();

            switch (postfix[i])
            {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    result = operand1 / operand2;
                    break;

                case '%':
                    result = operand1 % operand2;
                    break;

                default:
                    printf("Invalid operator\n");
                    return 1;
            }

            push(result);
        }
    }

    result = pop();

    printf("Result of postfix expression = %d\n", result);

    return 0;
}

