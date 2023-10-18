#include <stdio.h>

void swap(int *arr,int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    int j = low;
    int temp;
    for (; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr, i, j);
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quickSort(int *arr, int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}


int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size-1);
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
