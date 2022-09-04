#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * right;
    struct node * left;
};

struct node * newnode(int val){
    struct node * a;
    a=malloc(sizeof(struct node));
    a->data=val;
    a->right=NULL;
    a->left=NULL;
    return a;
}

void inorder(struct node * a){
    if (a==NULL){
        return;
    }
    inorder(a->left);
    printf("%d ",a->data);
    inorder(a->right);
}

struct node * inorderSuccessor(struct node * a){
    struct node * curr=a->right;
    while (curr && curr->left != NULL){
        curr=curr->left;
    }
    return curr;
}

struct node * delete(struct node * a,int val){
    struct node * ipr;
    if (a==NULL)
        return NULL;
    // if (a->left==NULL && a->right==NULL)
    //     free(a);
    if (val<a->data)
        a->left=delete(a->left,val);
    else if (val>a->data)
        a->right=delete(a->right,val);
    else{
        if (a->left==NULL){
            struct node * temp=a->right;
            free(a);
            return temp;
        }
        else if (a->right==NULL){
            struct node * temp=a->left;
            free(a);
            return temp;
        }
        struct node * temp=inorderSuccessor(a);
        a->data=temp->data;
        a->right=delete(a->right,temp->data);
    }
    return a;
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
    inorder(root);
    printf("\n");
    delete(root,44);
    inorder(root);
}