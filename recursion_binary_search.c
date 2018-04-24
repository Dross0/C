#include <stdio.h>

int recursion_binary_search(int value, int arr[], int min, int max);

int main(){
    int n;
    do{
        printf("Enter size of array: ");
        scanf("%d", &n);
    }
    while (n < 1);

    int arr[n];
    for (int i = 0; i < n; i++){
        int input;
        printf("a[%i] = ", i);
        scanf("%d", &input);
        arr[i] = input;
    }
    int val;
    printf("Enter value for search: ");
    scanf("%d", &val);
    if (recursion_binary_search(val, arr, 0, n)){
        printf("Value in array!\n");
    }
    else{
        printf("Value not in array!\n");
    }
}

int recursion_binary_search(int value, int arr[], int min, int max){
    int mid = (max + min) / 2;
    if (arr[mid] == value){
        return 1;
    }
    else if (min > max){
        return 0;
    }
    else if (arr[mid] > value){
        return recursion_binary_search(value, arr, min, mid-1);
    }
    else{
        return recursion_binary_search(value, arr, mid+1, max);
    }
}
