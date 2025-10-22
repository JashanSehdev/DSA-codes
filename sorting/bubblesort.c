#include<stdio.h>
#include<stdbool.h>

void swap (int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void bubblesort(int arr[], int n) {
    int i,j;
    bool swapped;
    for (i = 0; i < n - 1; ++i) {
        swapped = false;
        for (j = 0; j < n - 1 - i; ++j){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j],&arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false) break;
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n; ++i){
        printf("%d, ",arr[i]);
    }
    printf ("\n");
}

int main(){
    int arr [] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = 5;
    print (arr, n);
    bubblesort(arr, n);
    print(arr, n);
    return 0;
}