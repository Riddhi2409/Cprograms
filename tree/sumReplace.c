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
void sumReplace(struct node * a){
    if (a==NULL)
        return;
    sumReplace(a->left);
    sumReplace(a->right);
    if (a->left != NULL)
        a->data+=a->left->data;
    if (a->right !=NULL)
        a->data+=a->right->data;
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
    printf("\nInorder: ");Inorder(root);
    sumReplace(root);
    printf("\nInorder: ");Inorder(root);
    
}