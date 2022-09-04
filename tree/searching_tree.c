#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * newnode(int datas){
    struct node * a;
    a=malloc(sizeof(struct node));
    a->data=datas;
    a->left=NULL;
    a->right=NULL;
    return a;
}
struct node * search(struct node * q,int key){
    if (q==NULL){
        return NULL;
    }
    else if (q->data==key){
        return q;
    }
    else if (key<q->data){
        return search(q->left,key);
    }
    else{
        return search(q->right,key);
    }
}
void main()
{
    struct node * root;
    root=newnode(44);
    root->right=newnode(56);
    root->left=newnode(20);
    root->right->right=newnode(82);
    root->left->left=newnode(14);
    root->left->right=newnode(38);
    root->left->left->left=newnode(8);
    root->left->right->left=newnode(23);
    struct node * a=search(root,20);
    if (a!=NULL)
        printf("element found");
    else
        printf("element not found");
}