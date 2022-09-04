#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define max 50
int arr[max];
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
void push(int item)
{
    if (isfull())
    {
        printf("stack overflow\n");
        return;
    }
    top = top + 1;
    arr[top] = item;
}
int pop()
{
    if (isempty())
    {
        printf("stack underflow\n");
        return;
    }
    int value = arr[top];
    top = top - 1;
    return value;
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
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return 1;
    }
    return 0;
}
int post(char *s)
{
    int eval = 0, i = 0;
    while (s[i] != ')')
    {

        if (!operator(s[i]))
        {
            if (s[i + 1] == ',')
            {
                int c = s[i] - 48;
                push(c);
            }
            else
            {
                int q = 0;
                while (s[i] != ',')
                {
                    q = q * 10 + (s[i] - 48);
                    i++;
                }
                i--;
                push(q);
            }
        }
        else
        {
            int a = pop();
            int b = pop();
            switch (s[i])
            {
            case '+':
                eval = b + a;
                push(eval);
                break;
            case '-':
                eval = b - a;
                push(eval);
                break;
            case '*':
                eval = b * a;
                push(eval);
                break;
            case '/':
                eval = (int)b / a;
                push(eval);
                break;
            case '^':
                eval = pow(b, a);
                push(eval);
                break;
            }
        }
        i += 2;
    }
    eval = pop();
    return eval;
}
void main()
{
    char *c;
    c = malloc(sizeof(char) * 50);
    printf("enter the expression: ");
    scanf("%s", c);
    strcat(c, ",)");
    int eo = post(c);
    printf("%d", eo);
    // int d=;
    // printf("%d",d);
}