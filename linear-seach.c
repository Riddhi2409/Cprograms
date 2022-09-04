#include<stdio.h>
int findElement(int arr[],int n,int key){
    for (int i=0;i<n;i++){
        if (arr[i]==key)
            return i;
    }
    printf("element not found");
    return -1;
}
void main()
{
    printf("enter the no. of length: ");
    int n,ele,index;
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements: ");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the element to be searched: ");
    scanf("%d",&ele);
    index=findElement(arr,n,ele);
    printf("the element is found at index: %d",index);
}