#include <stdio.h>
#include <string.h>
#define max 5
int queue[max], rear = -1, front = -1;
int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}
int isFull()
{
    if ((front==(rear+1) || (front==0 && rear==max-1)))
        return 1;
    return 0;
}
void insert()
{
    if (isFull())
    {
        printf("queue overflow\n");
        return;
    }
    int item;
    printf("enter the item: ");
    scanf("%d", &item);
    if (rear == front && rear==-1)
    {
        front=0;
        rear=0;
    }
    else if (rear == max-1){
        rear=0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = item;
}
void delete ()
{
    if (isEmpty())
    {
        printf("queue underflow\n");
        return;
    }
    else if (front == rear && front != -1)
    {
        front = -1;
        rear = -1;
    }
    else if (front==max-1)
    {
        front = 0;
    }
    else {
        front=front+1;
    }
    
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty..");
    }
    else if (front==rear && rear !=-1){
        printf("%d ",queue[i]);
    }
    else if (rear>front){
        for (i=front ;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
    else{
        while (1){
            if (i>=0 && i<=max-1){
                printf("%d ",queue[i]);
                if (i == rear){
                    break;
                } 
                i++;

            }
            else{
                i=0;
                printf("%d ",queue[i]);
                if (i == rear){
                    break;
                }
                i++;
            }
        }
    }
    printf("\n");
    
}
void main()
{
    int choice;
    do
    {
        printf("enter 1 for insert\nenter 2 for delete\nenter 3 for display\nenter 4 for termination: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            printf("%d",front);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        }
    } while (choice != 0);
    printf("%d", front);
}