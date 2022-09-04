#include<stdio.h>
void quicksort(int arr[],int low,int high){
    int i,j,pivot,temp;
    if(low < high){
        pivot=low;
        i=low+1;
        j=high;
        while (i<j){
            while(arr[i]<= arr[pivot] && i<=high){
                i++;
            }
            while(arr[j]>=arr[pivot]){
                j--;
            }
            if (i<j){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
    }
}
void main()
{
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    quicksort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
}