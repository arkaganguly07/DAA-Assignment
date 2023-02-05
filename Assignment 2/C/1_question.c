/*
1. Write a program to sort a list of element in an Array using Quick Sort. Show
the running time complexity w.r.t different input cases (best/average/worst).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
 
    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    
    printf("\n");
}

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    clock_t start, end;
    double time_taken;
    
    int n = sizeof(arr) / sizeof(arr[0]);

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    printf("The sorted array: ");
    printArray(arr, n);

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n The elapsed time is %f seconds \n", time_taken);

    return 0;
}