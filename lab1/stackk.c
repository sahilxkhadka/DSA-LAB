#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct stack
{
    int top;
    int arr[MAX];
};

void pop(struct stack *s)
{
    if (s->top == -1)
        printf("Stack is empty");
    else
    {
        printf("The popped element is %d\n", s->arr[s->top]);
        s->top--;
    }
}

void display(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Empty Stack");
    }
    else
    {
        printf("The elements in the stack are:\n");
        for (int i = s->top; i > -1; i--)
        {
            printf("%d\t", s->arr[i]);
        }
    }
}

void push(struct stack *s, int item)
{
    if (s->top == MAX - 1)
    {
        printf("Stack is full");
    }
    else
    {
        s->top++;
        s->arr[s->top] = item;
    }
}

int main()
{
    struct stack s = {-1};
    int temp = 0, x;
    while (temp != 4)
    {
        printf("\nWhat operation would you like to perform?\n1.Add element to stack\n2.Remove element from stack\n3.Display elements in the stack\n4.Exit\n");
        scanf("%d", &temp);
        if (temp == 1)
        {
            printf("Enter the element you want to push:\n");
            scanf("%d", &x);
            push(&s, x);
        }
        else if (temp == 2)
        {
            pop(&s);
        }
        else if (temp == 3)
        {
            display(&s);
        }
        else
        {
            break;
        }
    }
    printf("\nStack operations completed.");
    return 0;
}
