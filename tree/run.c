#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int powx;
    struct node *next;
}*poly;
struct node* createPoly()
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    poly=n;
    printf("Enter Coeff and power:");
    scanf("%d %d",&n->coeff,&n->powx);
    int opt;
    printf("Do you want to continue(0/1):");
    scanf("%d",&opt);
    while(opt)
    {
        struct node *p=(struct node *)malloc(sizeof(struct node));
        n->next=p;
        printf("Enter Coeff and power:");
        scanf("%d %d",&p->coeff,&p->powx);
        p->next=NULL;
        n=p;
        printf("Do you want to continue(0/1):");
        scanf("%d",&opt);
    }
    return poly;
}
int main()
{
    printf("First Polynomial: \n");
    struct node *poly1 = createPoly();
    printf("Second Polynomial: \n");
    struct node *poly2 = createPoly();

    printf("Resultant Polynomial\n");
    struct node *p1=poly1;
    struct node *p2=poly2;
    struct node *r=(struct node *)malloc(sizeof(struct node));
    struct node *head=r;
    while(p1!=NULL &&  p2!=NULL)
    {
        if((p1->powx)>(p2->powx))
        {
            r->coeff=p1->coeff;
            r->powx=p1->powx;
            p1=p1->next;
        }
        else if((p2->powx)>(p1->powx))
        {
            r->coeff=p2->coeff;
            r->powx=p2->powx;
            p2=p2->next;
        }
        else
        {
            r->coeff=p1->coeff+p2->coeff;
            r->powx=p1->powx;
            p1=p1->next;
            p2=p2->next;
        }
        if(p1==NULL && p2==NULL)
            break;
        struct node *s=(struct node *)malloc(sizeof(struct node));
        r->next=s;
        r=s;
    }
    while(p1!=NULL)
    {
        r->coeff=p1->coeff;
        r->powx=p1->powx;
        p1=p1->next;
        if(p1==NULL)
            break;
        struct node *s=(struct node *)malloc(sizeof(struct node));
        r->next=s;
        r=s;
    }
    while(p2!=NULL)
    {
        r->coeff=p2->coeff;
        r->powx=p2->powx;
        p2=p2->next;
        if(p2==NULL)
            break;
        struct node *s=(struct node *)malloc(sizeof(struct node));
        r->next=s;
        r=s;
    }
    r->next=NULL;


    struct node *q=head;
    while(q!=NULL)
    {
        printf("%dx^%d",q->coeff,q->powx);
        q=q->next;
        if(q!=NULL)
            printf("+");
    }
}