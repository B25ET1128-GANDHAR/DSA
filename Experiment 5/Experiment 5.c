#include <stdio.h>
#define MAX 5

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
        printf("%d pushed into stack.\n", value);
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack contents are :\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
        printf("TOP is at position : %d\n", top + 1);
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n    STACK MENU    \n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter Choice :");
        scanf("%d", &choice);

                switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program exited\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
} 
