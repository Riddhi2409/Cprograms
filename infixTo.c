#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 50
char arr[max];
int top = -1;
int isfull()
{
    if (top == max - 1)
    {
        return 1;
    }
    return 0;
}
int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
void push(char item)
{
    if (isfull())
    {
        printf("stack overflow");
    }
    else
    {
        top = top + 1;
        arr[top] = item;
    }
}
char pop()
{
    if (isempty())
    {
        return;
    }
    else
    {
        char val = arr[top];
        top = top - 1;
        return val;
    }
}
void display()
{
    if (isempty())
    {
        printf("stack underflow\n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}
char peek()
{
    if (isempty())
    {
        printf("stack underflow\n");
    }
    else
    {
        return arr[top];
    }
}
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
int operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return 1;
    }
    return 0;
}
int brackets(char c){
    if (c== '(' || c==')'){
        return 1;
    }
    else {
        return 0;
    }
}
char * postx(char *infix,char *postfix)
{
    int i=0,j=0;
    while (infix[i] != '\0')
    {
        if (!operator(infix[i]) && !brackets(infix[i])) 
        {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == '(')
        {
            push('(');
        }
        else if (infix[i] == ')')
        {
            while (arr[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            char o=pop();
        }
        else
        {
            while (Prec(infix[i]) <= Prec(arr[top])){
                postfix[j]=pop();
                j++;
            }
            push(infix[i]);
        }
        i++;
    }
    postfix[j]='\0';
    return postfix;
}

void main()
{
    char *c;
    c = malloc(sizeof(char) * 50);
    printf("enter the expression: ");
    scanf("%s", c);
    strcat(c, ")");
    push('(');
    char * s;
    s=malloc(sizeof(char)*50);
    s=postx(c,s);
    printf("%s\n",s);
    
}