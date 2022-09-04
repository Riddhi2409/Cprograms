#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * createNode(int val){
    struct node * b;
    b=malloc(sizeof(struct node));
    b->data=val;
    b->left=NULL;
    b->right=NULL;
    return b;
}

int max(int a,int b){
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

struct node * RRotation(struct node * x){
    struct node *y=x->left;
    struct node * t2=y->right;
    y->right=x;
    x->left=t2;
    return y;
}

struct node * LRotation(struct node * x){
    struct node * y=x->right;
    struct node * t2=y->left;
    y->left=x;
    x->right=t2;
    return y;
}

int getbalanced(struct node * a){
    if (a==NULL)
        return 0;
    return height(a->left)-height(a->right);
}

struct node * insert(struct node * a,int val){
    if (a==NULL){
        return createNode(val);
    }
    if (a->data < val)
        a->right=insert(a->right,val);
    else if (a->data > val)
        a->left=insert(a->left,val);

    int bf=getbalanced(a);
    printf("-----%d----\n",a->data);
    if(bf>1 && val < a->left->data){
            return RRotation(a);
    }
    // Right Right Case
        if(bf<-1 && val > a->right->data){
            return LRotation(a);
        }
    // Left Right Case
    if(bf>1 && val > a->left->data){
            a->left = LRotation(a->left);
            return RRotation(a);
        }
    // Right Left Case
    if(bf<-1 && val < a->right->data){
            a->right = RRotation(a->right);
            return LRotation(a);
    }
    return a;
}

void preorder(struct node * a){
    if (a==NULL)
        return;
    printf("%d ",a->data);
    preorder(a->left);
    preorder(a->right);
}

void main()
{
    struct node * root=NULL;
    int a,co;
    while (1){
        printf("enter data: ");
        scanf("%d",&a);
        root=insert(root,a);
        preorder(root);
        printf("\n");
        printf("enter a: ");
        scanf("%d",&co);
        if (co==0){
            break;
        }
    }
    
}