#include<stdio.h>
void swap (int * a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int p,int r){
    int x=arr[r];
    int j=p-1;
    for (int i=p;i<=r-1;i++){
        if (arr[i]<=x){
            j=j+1;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[j+1],&arr[r]);
    return j+1;
}
void quickSort(int arr[],int p,int r){
    if (p<r){
        int q=partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}
int main(){
    printf("enter the no. of length: ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements: ");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}