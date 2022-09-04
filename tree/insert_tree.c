#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * right;
    struct node * left;
};

struct node * newnode(int val){
    struct node * a;
    a=malloc(sizeof(struct node));
    a->data=val;
    a->left=NULL;
    a->right=NULL;
    return a;
}

void insert(struct node * a,int key){
    struct node * prev=NULL;
    while (a!=NULL){
        prev=a;
        if(key==a->data){
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key<a->data){
            a=a->left;
        }
        else{
            a=a->right;
        }
    }
    struct node* new = newnode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
    // printf("%d",a->data);
}

struct node* insertion(struct node* node, int key)
{
    if (node == NULL)
        return newnode(key);

    if (key < node->data)
        node->left = insertion(node->left, key);
    else if (key > node->data)
        node->right = insertion(node->right, key);
    return node;
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
    root=insertion(root,50);
    printf("\n%d\n",root->data);
    Inorder(root);
}