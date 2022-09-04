#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int max(int arr[],int n){
    int max=INT_MIN;
    for (int i=0;i<=n;i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
void countSort(int arr[],int n){
    int num=max(arr,n);
    int i,j;
    int * count;
    count=malloc(sizeof(int)*(num+1));
    for (i=0;i<=num;i++){
        count[i]=0;
    }
    for (i=0;i<=n;i++){
        count[arr[i]]=count[arr[i]]+1;
    }
    i=0;j=0;
    while (i<=num){
        if(count[i]>0){
            arr[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
    }
}
void main()
{
    int arr[7] = {8, 7, 3, 3, 9, 8, 10};
    countSort(arr, 6);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
}
