#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>
int max(int arr[],int n){
    int max=INT_MIN;
    for (int i=0;i<=n;i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
void countSort(int arr[],int n,int exp){
    int i,j;
    int count[10]={0};
    int output[n+1];
    for (i=0;i<=n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10]-1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i <= n; i++)
        arr[i] = output[i];
}
void radixSort(int arr[],int n){
    int num=max(arr,n);
    for (int exp = 1; num / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void main()
{
    int arr[9] = {348,143,361,423,538,128,321,543,366};
    radixSort(arr, 8);
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", arr[i]);
    }
}