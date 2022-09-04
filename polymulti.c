#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int exop;
    int coeff;
    struct node *link;
};
struct node *insertend(struct node *x, int coff, int expo)
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
    for (int i = 0; i < totalTerms; i++)
    {
        int co, ex;
        scanf("%d %d", &co, &ex);
        x = insertend(x, co, ex);
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
struct node *polymulti(struct node *p1, struct node *p2, struct node *p3)
{
    struct node * temp=p2;
    while (p1)
    {
        while (temp)
        {
            p3 = insertend(p3, p1->coeff * temp->coeff, p1->exop + temp->exop);
            temp = temp->link;
        }
        p1 = p1->link;
        temp=p2;
    }
    return p3;
}
void main()
{
    struct node *p1 = NULL ;
    struct node *p2 = NULL;
    p1 = create_polynomial(p1, 2);
    p2 = create_polynomial(p2, 2);
    display(p1);
    display(p2);
    struct node * p3=NULL;
    p3=polymulti(p1,p2,p3);
    display(p3);
}