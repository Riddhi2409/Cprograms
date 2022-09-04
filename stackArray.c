#include<stdio.h>
#define max 4
int arr[max];
int top=-1;
int isfull(){
    if (top == max-1){
        return 1;
    }
    return 0;
}
int isempty(){
    if (top == -1){
        return 1;
    }
    return 0;
}
void push(){
    if (isfull()){
        printf("stack overflow\n");
        return;
    }
    top=top+1;
    int item;
    printf("enter the item: ");
    scanf("%d",&item);
    arr[top]=item;
}
int pop(){
    if (isempty()){
        printf("stack underflow\n");
        return;
    }
    int value=arr[top];
    top=top-1;
    return value;
}
void display(){
    if (isempty()){
        printf("stack underflow\n");
        return;
    }
    for (int i=top;i>=0;i--){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int peek(){
    if (isempty()){
        printf("stack underflow\n");
        return;
    }
    return arr[top];
}
void main()
{
    int val;
    int choice;
    do {
        printf("enter 1 for push\nenter 2 for pop\nenter 3 for peek\nenter 4 for dispaly\nenter 0 for terminate: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                val=peek();
                printf("the peek value is %d\n",val);
                break;
            case 4:
                display();
                break;
        }
    }while(choice!=0);  
}