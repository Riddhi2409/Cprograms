#include<stdio.h>


int size=0;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[],int size,int i){
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;
    if (size==1){
        printf("single element\n");
        return;
    }
    if (l < size && arr[l] < arr[smallest]){
        smallest=l;
    }
    if (r<size && arr[r] < arr[smallest]){
        smallest=r;
    }
    if (smallest!=i){
        swap(&arr[i],&arr[smallest]);
        heapify(arr,size,smallest);
    }
}

void insert(int arr[],int num){
    if(size==0){
        arr[size]=num;
        size++;
    }
    else{
        arr[size]=num;
        size+=1;
        for (int i = size/2 -1 ; i>=0 ;i--){
            heapify(arr,size,i);
        }
    }
}
void printArray(int arr[],int size){
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void main()
{
    int array[10];
    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);

    printf("Max-Heap array: ");
    printArray(array, size); 
}