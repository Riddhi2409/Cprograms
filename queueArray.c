#include<stdio.h>
#include<string.h>
#define max 5
int queue[max],rear=-1,front=-1;
int isEmpty(){
    if (front == -1)
        return 1;
    return 0;
}
int isFull(){
    if (rear == max -1)
        return 1;
    return 0;
}
void insert(){
    if (isFull()){
        printf("queue overflow\n");
        return;
    }
    int item;
    printf("enter the item: ");
    scanf("%d",&item);
    if (front ==-1){
        rear++;
        front++;
        queue[rear]=item;
    }
    else{
        rear=rear+1;
        queue[rear]=item;
    }
}
int delete(){
    if (isEmpty()){
        printf("queue underflow\n");
        return;
    }
    int pop=queue[front];
    if (front==rear && front !=-1 ){
        front=-1;
        rear=-1;
    }
    
    else{
        front=front+1;
    }
}
void display(){
    for (int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
void main()
{
    int choice;
    do {
        printf("enter 1 for insert\nenter 2 for delete\nenter 3 for display\nenter 4 for termination: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        }
    }while(choice != 0);
    printf("%d",front);
}