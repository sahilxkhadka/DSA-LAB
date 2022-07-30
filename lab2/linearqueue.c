#include<stdio.h>
#define MAX 10

struct linearQueue {
    int front;
    int rare;
    int item[MAX];
};

//initially front = 0
//rare = -1
//if(p -> rare < p -> front) { Empty}
// if(rare == MAX -1) {Full}

void nqueue(struct linearQueue *p) {
    if(p -> rare == MAX -1) {
        printf("Queue is Full!");
    } else {
        p -> rare++;
        int queueEl;
        printf("Enter a element to insert in Queue: ");
        scanf("%d", &queueEl);
        p -> item[p -> rare] = queueEl;
        printf("%d is inserted in Queue!\n", p -> item[p -> rare]);
    }
}

void dqueue(struct linearQueue *p) {
    if(p -> rare < p -> front) {
        printf("Queue is Empty!");
    } else {
        printf("%d is deleted form Queue!\n", p -> item[p -> front]);
        p -> front++;
    }
}

void display(struct linearQueue *p) {
    if(p -> rare < p -> front) {
        printf("Queue is Empty!");
    } else {
        for(int i = p -> front; i <= p -> rare; i++) {
            printf("%d, ", p -> item[i]);
        }
        printf("\n");
    }
}

int main() {
    int userCommand;
    struct linearQueue s = { 0, -1};

    do{
        printf("Enter a following command to perform following operation on Queue:\n");
        printf("1 to Perfrom INSERT operation on Queue!\n");
        printf("2 to Perfrom DELETE operation on Queue!\n");
        printf("3 to Perfrom DISPLAY operation on Queue!\n");
        printf("4 to Perfrom EXIT program!\n");
        scanf("%d", &userCommand);

        if(userCommand == 1) {
            nqueue(&s);
        } else if(userCommand == 2) {
            dqueue(&s);
        } else if(userCommand == 3) {
            display(&s);
        } else if(userCommand == 4) {
            printf("Program Exited!");
        } else {
            printf("Invalid command!\n");
        }
    } while(userCommand != 4);

    return 0;
}