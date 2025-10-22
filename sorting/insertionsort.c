#include<stdio.h>
#include<stdbool.h>

void swap (int *i, int *j);

void insertionsort(int arr[], int n) {
    int i, j;

    for (i = 1; i < n; ++i) {
        j = i;
        while ( j > 0 && arr[j-1] > arr[j]) {
            swap (&arr[j-1], &arr[j]);
            j = j - 1;
        }
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void swap (int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}


int main() {
    int arr [] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = 5;
    print (arr, n);
    insertionsort(arr, n);
    print(arr, n);
    return 0;
}