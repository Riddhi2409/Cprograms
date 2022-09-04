#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * after;
};

void transversal(struct node * x){
    struct node * ptr = x ;
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->after;
    }
    printf("\n");
}

struct node * insertionbegin(struct node * x){
    struct node * avail;
    avail=malloc(sizeof(struct node));
    int item;
    printf("enter the value: ");
    scanf("%d",&item);
    avail->data=item;
    avail->prev=NULL;
    avail->after=x;
    x->prev=avail;
    x=avail;
    return x;
}

struct node * insertionend(struct node * x){
    struct node * new ;
    struct node * ptr;
    new=malloc(sizeof(struct node));
    int items;
    printf("enter the item: ");
    scanf("%d",&items);
    new->data=items;
    new->after=NULL;
    if (x == NULL){
        x=new;
        new->prev=NULL;
        return x;
    }
    else
        ptr=x;
    while (ptr->after !=NULL){
        ptr = ptr->after;
    }
    ptr->after=new;
    new->prev=ptr;
    return x;
}

struct node * insertionmiddle(struct node * x){
    struct node * new ;
    struct node * ptr;
    struct node *pdr;
    new=malloc(sizeof(struct node));
    int item,n,i=0;
    printf("enter the item: ");
    scanf("%d",&item);
    printf("enter the position of the insertion: ");
    scanf("%d",&n);
    while(i<n){
        if (i==0){
            ptr=x;
        }
        else if (i==1){
            pdr=x;
            ptr=ptr->after;
        }
        else {
            ptr=ptr->after;
            pdr=pdr->after;
        }
        i++;
    }
    new->data=item;
    pdr->after=new;
    new->prev=pdr;
    new->after=ptr;
    return x;
}

struct node * deletionbegin(struct node * x){
    
    x->after->prev=NULL;
    x=x->after;
    return x;

}

struct node * deletionend(struct node * x){
    struct node * ptr;
    if (x->after == NULL){
        x=NULL;
    }
    else {
        ptr = x;
    }
    while (ptr->after->after != NULL)
        ptr=ptr->after;
    ptr->after=NULL;
    return x;
}

struct node * deletionmiddle(struct node * x){
    struct node * ptr;
    struct node * pdr;
    int n,i=0;
    printf("enter the position for the deletion: ");
    scanf("%d",&n);
    while(i<n){
        if (i==0){
            ptr=x;
        }
        else if (i==1){
            pdr=x;
            ptr=ptr->after;
        }
        else {
            ptr=ptr->after;
            pdr=pdr->after;
        }
        i++;
    }
    pdr->after=ptr->after;
    ptr->prev=pdr;
    return x;
}

void main()
{
    struct node * first;
    first=malloc(sizeof(struct node));
    int item;
    printf("enter the value: ");
    scanf("%d",&item);
    first->data=item;
    first->prev=NULL;
    struct node * temp = first;
    int val,choice;
    for (int i=0;i<9;i++)
    {
        struct node * newnode;
        newnode=malloc(sizeof(struct node));
        printf("enter the value: ");
        scanf("%d",&val);
        newnode->data= val;
        newnode->prev=temp;
        temp->after=newnode;
        temp=newnode;
        newnode->after=NULL;
    }
    do {
        printf("enter 1 for insertion at begining\nenter 2 for insertion at end\nenter 3 for insertion at middle\nenter 4 for deletion at begining\nenter 5 for deletion at end\nenter 6 for deletion at middle\nenter 7 for display\nenter 0 for terminate: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                first=insertionbegin(first);
                break;
            case 2:
                first=insertionend(first);
                break;
            case 3:
                first=insertionmiddle(first);
                break;
            case 4:
                first=deletionbegin(first);
                break;
            case 5:
                first=deletionend(first);
                break;
            case 6:
                first=deletionmiddle(first);
                break;
            case 7:
                transversal(first);
                break;
        }
    }while (choice !=0);

}