#include<stdio.h>
int binarySearch(int arr[],int low,int high,int key){
    if (high<low)
        return -1;
    int mid=(low+high)/2;
    if (key==arr[mid])
        return mid;
    else if (key > arr[mid]){
        binarySearch(arr,mid+1,high,key);
    }
    else{
        binarySearch(arr,low,mid-1,key);
    }
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
    index=binarySearch(arr,0,n,ele);
    printf("the element is found at index: %d",index);
} 
