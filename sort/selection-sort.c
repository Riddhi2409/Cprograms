#include<stdio.h>
void swap (int * x , int * y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void selectionSort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        int min_index=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(&arr[min_index],&arr[i]);
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
    selectionSort(arr,n);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}