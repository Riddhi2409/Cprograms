#include <stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int n1=high-low+1;
    int b[n1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    i=low;
    for (k = 0; k < n1; k++)
    {
        arr[i] = b[k];
        i++;
    }
}
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void main()
{
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    mergesort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
}