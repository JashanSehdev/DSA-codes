#include <stdio.h>
#include <stdbool.h>

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void selectionsort(int arr[], int n)
{
    int min;
    int i, j;

    for (int i = 0; i < n - 1; ++i)
    {
        min = i;
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                min = (arr[min] > arr[j]) ? j : min;
            }
        }
         if (min != i)
            {
                swap(&arr[i], &arr[min]);
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


int main()
{
    int arr [] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = 5;
    print (arr, n);
    selectionsort(arr, n);
    print(arr, n);
    return 0;
}