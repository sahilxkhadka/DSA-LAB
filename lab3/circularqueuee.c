#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5

struct CQueue
{
    int front;
    int rear;
    int data[MAX];
};

void dequeue(struct CQueue *);
void enqueue(struct CQueue *);
void display(struct CQueue *);
void main()
{
    int ch;
    struct CQueue cq;

    cq.front = MAX - 1;
    cq.rear = MAX - 1;

    while (1)
    {

        printf("Enter queue operation:\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(&cq);
            break;
        case 2:
            dequeue(&cq);
            break;
        case 3:
            display(&cq);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid operation!\n");
        }
    }
}
void enqueue(struct CQueue *cq)
{

    int num;

    if ((cq->rear + 1) % MAX == cq->front)
    {

        printf("Queue is full!\n");
    }
    else
    {
        printf("Enter a number to push: ");
        scanf("%d", &num);

        cq->rear = (cq->rear + 1) % MAX;
        printf("rear = %d", cq->rear);
        cq->data[cq->rear] = num;
    }
}
void dequeue(struct CQueue *cq)
{

    if (cq->rear == cq->front)
    {

        printf("Queue is empty!\n");
    }
    else
    {

        cq->front = (cq->front + 1) % MAX;
        printf("The dequeued element = %d\n", cq->data[cq->front]);
    }
}
void display(struct CQueue *cq)
{

    int i;
    if (cq->rear == cq->front)
    {
        printf("Queue is empty!\n");
    }
    else
    {

        printf("Queue elements are: \n");

        for (i = (cq->front + 1) % MAX; i != cq->rear; i = (i + 1) % MAX)
        {
            printf("%d\n", cq->data[i]);
        }
        printf("%d\n", cq->data[cq->rear]);
    }
}
