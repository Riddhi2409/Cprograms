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
void preorder(struct node * a){
    struct node * ptr;
    ptr=a;
    if (a==NULL){
        return;
    }
    printf("%d ",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}
void Inorder(struct node * a){
    struct node * ptr;
    ptr=a;
    if (a==NULL){
        return;
    }
    Inorder(ptr->left);
    printf("%d ",ptr->data);
    Inorder(ptr->right);
}
void Postorder(struct node * a){
    struct node * ptr;
    ptr=a;
    if (a==NULL){
        return;
    }
    Postorder(ptr->left);
    Postorder(ptr->right);
    printf("%d ",ptr->data);
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
    printf("\npreorder: ");preorder(root);
    printf("\nInorder: ");Inorder(root);
    printf("\npostorder: ");Postorder(root);
    
}