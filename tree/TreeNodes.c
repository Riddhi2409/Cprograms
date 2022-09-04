#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node * newnode(int datas){
    struct node * node1;
    node1=malloc(sizeof(struct node));
    node1->data=datas;
    node1->left=NULL;
    node1->right=NULL;
    return node1;
}
int countNodes(struct node * ptr){
    if (ptr==NULL){
        return 0;
    }
    return countNodes(ptr->left)+countNodes(ptr->right)+1;
}
int sumNodes(struct node * ptr){
    if (ptr==NULL){
        return 0;
    }
    return sumNodes(ptr->left)+sumNodes(ptr->right)+ptr->data;
}
void main()
{
    struct node* root;
    root=newnode(44);
    root->right=newnode(56);
    root->left=newnode(20);
    root->right->right=newnode(82);
    root->left->left=newnode(14);
    root->left->right=newnode(38);
    root->left->left->left=newnode(8);
    root->left->right->left=newnode(23);
    printf("no od nodes is %d\n",countNodes(root));
    printf("sum of all nodes is %d\n",sumNodes(root));   
}