#include<stdio.h>
void insertionSort(int arr[],int n){
    int j,k;
    for (int i=0;i<n;i++){
        k=arr[i];
        for ( j = i -1 ; j>=0 && k<arr[j];j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=k;
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
    insertionSort(arr,n);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}