#include<stdio.h>
int fibo(int);
void main()
{
    int ans=fibo(4);
    printf("%d",ans);
}
int fibo(int num){
    if (num==0){
        return 0;
    }
    else if (num==1){
        return 1;
    }
    else{
        return fibo(num-1)+fibo(num-2);
    }
}