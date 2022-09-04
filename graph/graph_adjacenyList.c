#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}node;

typedef struct list{
    node * head;
}list;

list * adjList[4]={0};

void addNode(int s, int d){
    node * dest , *src ,*temp;
    if (adjList[s]->head==NULL){
        src=malloc(sizeof(node));
        src->data=s;
        src->next=NULL;
        adjList[s]->head=src;    }
    dest=malloc(sizeof(node));
    dest->data=d;
    dest->next=NULL;
    temp=adjList[s]->head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=dest;
}

void printList(){
    for (int i=0;i<4;i++){
        node * p=adjList[i]->head;
        printf("adjacency list of vertex %d\n",i );
        while (p){
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
}

void main()
{
    
    for (int i=0;i<4;i++){
        adjList[i]=malloc(sizeof(list));
        adjList[i]->head=NULL;
    }
    addNode(0,1);
    addNode(0,3);
    addNode(1,3);
    printList();
}