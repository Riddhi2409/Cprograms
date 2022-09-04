#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * link;
};

struct node * reversal(struct node * x,int totalEle){
    int arr[10],i=0;
    struct node * ptr;
    ptr=x;
    while (ptr != NULL){
        arr[i]=ptr->data;
        ptr=ptr->link;
        i++;
    }
    i=i-1;
    ptr=x;
    for (i;i>=0;i--){
        ptr->data=arr[i];
        ptr=ptr->link;
    }
    return x;
}
void transversal(struct node * x){
    struct node * ptr = x ;
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
int main(){
    struct node * first;
    first=malloc(sizeof(struct node));
    int item,n;
    printf("no.of item to be inserted : ");
    scanf("%d",&n);
    printf("enter the value: ");
    scanf("%d",&item);
    first->data=item;
    struct node * temp = first;
    int val,choice;
    first->link=NULL;
    for (int i=0;i<n-1;i++)
    {
        struct node * newnode;
        newnode=malloc(sizeof(struct node));
        printf("enter the value: ");
        scanf("%d",&val);
        newnode->data= val;
        temp->link=newnode;
        temp=newnode;
        newnode->link=NULL;
    }
    int n=10;
    printf("before reversal\n");
    transversal(first);
    first=reversal(first,n);
    printf("after reversal\n");
    transversal(first);
}