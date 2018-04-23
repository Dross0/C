#include <stdio.h>

void selectionSort(int arr[]);

int main(void){
    int arr[10] = {2, 4, 8, 9, 10, 50, 9, 1, 80, 11};
    selectionSort(arr);
}


void selectionSort(int arr[]){
    int n = 10;
    for (int i = 0; i < n-1; i++){
        int min = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (min != i){
            int tmp = arr[min];
            arr[min] = arr[i];
            arr[i] = tmp;
        }
    }
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
