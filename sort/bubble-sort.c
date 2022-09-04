#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int arr[], int n){
    int k,temp;
    for (k=0;k<n;k++){
        int i=0,flag=0;
        while (i<n-k-1){
            if (arr[i]> arr[i+1]){
                temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
                flag=1;
            }
            i++;
        }
        if (flag==0){
            break;
        }
    }
}
void main()
{
    printf("enter the no. of length: ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements: ");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}