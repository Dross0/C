#include <stdio.h>

void bubbleSort(int arr[], int arrLen);
void swap(int *x, int *y);
void printArray(int arr[]);

void main(void){
    int arr[10] = {2, 4, 8, 9, 10, 50, 9, 1, 80, 11};
    bubbleSort(arr, 10);
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    printArray(arr);
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[]){
    int n = 10;
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}
