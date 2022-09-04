#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node * newnode(int datas)
{
    struct node * nodes;
    nodes = (struct node * )malloc(sizeof(struct node));
    nodes->data = datas;
    nodes->left = NULL;
    nodes->right = NULL;
    return (nodes);
}
int max(int a , int b){
    if (a>b)
        return a;
    return b;
}

int height(struct node * a){
    if (a==NULL)
        return 0;
    int lheight=height(a->left);
    int rheight=height(a->right);
    return max(lheight,rheight)+1;
}
int diameter(struct node * a){
    if (a==NULL)
        return 0;
    int lh=height(a->left);
    int rh=height(a->right);
    int rd=diameter(a->right);
    int ld=diameter(a->left);
    return max(lh+rh+1 ,max( rd , ld));
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
    printf("%d ", height(root));
    printf("%d ", diameter(root));
    
}