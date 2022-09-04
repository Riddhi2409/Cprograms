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
int search(int arr[], int start, int end, int curr)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (arr[i] == curr){
            return i;
        }
    }
}
struct node * buildTree(int postorder[] ,int inorder[] , int start ,int end){
    static int idx= 7;

     if (start>end)
        return NULL;

    int curr=postorder[idx];
    idx--;

    struct node * ptr;
    ptr=newnode(curr);

    if(start == end)
        return ptr;
    
    int pos =search(inorder,start,end,curr);
    ptr->right=buildTree(postorder,inorder,pos+1,end);
    ptr->left=buildTree(postorder,inorder,start,pos-1);
    return ptr;
}
void Inorder(struct node *a)
{
    struct node *ptr;
    ptr = a;
    if (a == NULL)
    {
        return;
    }
    Inorder(ptr->left);
    printf("%d ", ptr->data);
    Inorder(ptr->right);
}
void main()
{
    int postorder[] = {8,14,23,38,20,82,56,44};
    int inorder[] = {8,14,20,23,38,44,56,82};
    struct node * root = buildTree(postorder, inorder, 0, 7);
    Inorder(root);
}