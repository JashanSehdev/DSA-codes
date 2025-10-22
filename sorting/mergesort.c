#include<stdio.h>
#include<stdbool.h>


void merge (int arr[], int left, int right, int mid) {
    
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int l1[n1], l2[n2];

    for (int i = 0; i < n1; ++i) {
        l1[i] = arr[left + i];
    }

    for (int j = 0; j < n2; ++j) {
        l2[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (l1[i] <= l2[j]) {
            arr[k] = l1[i];
            i++;
        } else {
            arr[k] = l2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = l1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = l2[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right, mid );
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}