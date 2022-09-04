#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int exop;
    int coeff;
    struct node *link;
};
struct node * insertend(struct node *x, int coff, int expo)
{
    struct node *ptr;
    struct node *new;
    new = malloc(sizeof(struct node));
    new->coeff = coff;
    new->exop = expo;
    new->link = NULL;
    if (x == NULL)
    {
        x = new;
        return x;
    }
    else
    {
        ptr = x;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
        return x;
    }
}
struct node *create_polynomial(struct node *x, int totalTerms)
{
    for (int i = 0; i < totalTerms ; i++)
    {
        int co,ex;
        scanf("%d %d",&co,&ex);
        x=insertend(x,co,ex);
    }
    return x;
}
void display(struct node *x)
{
    struct node *temp;
    temp = x;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exop);
        temp = temp->link;
        if (temp != NULL && temp->coeff != 0)
        {
            printf("+");
        }
    }
    printf("\n");
}
struct node *polyadd(struct node *poly1, struct node *poly2, struct node *poly)
{
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exop > poly2->exop)
        {
            poly=insertend(poly, poly1->coeff, poly1->exop);
            poly1 = poly1->link;
        }
        else if (poly2->exop > poly1->exop)
        {
            poly=insertend(poly, poly2->coeff, poly2->exop);
            poly2 = poly2->link;
        }
        else{
            poly=insertend(poly, poly2->coeff + poly1->coeff, poly2->exop);
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
    }
    while (poly1 != NULL)
    {
        poly=insertend(poly, poly1->coeff, poly1->exop);
        poly1 = poly1->link;
    }
    while (poly2 != NULL)
    {
        poly=insertend(poly, poly2->coeff, poly2->exop);
        poly2 = poly2->link;
    }
    return poly;
}
void main()
{
    struct node *p1=NULL;
    struct node *p2=NULL;
    struct node *p3=NULL;
    p1 = create_polynomial(p1, 2);
    p2 = create_polynomial(p2, 2);
    display(p1);
    display(p2);
    p3 = polyadd(p1, p2, p3);
    display(p3);
}