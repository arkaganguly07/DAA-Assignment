/*
3. Write a program to perform selection sort using dynamic memory allocation.
   Show the running time complexity w.r.t different input cases. Finally comment that whether it
   is matching with the expected complexity of O(n^2) or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; ++i)
    {
        min_idx = i;
        for (j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;

            if (min_idx != i)
                swap(&arr[min_idx], &arr[i]);
        }
        
    }
    
}

void printArray(int arr[], int n) {
    int i;

    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);

    printf("\n");
}

int main(void) {
    int *arr, n, i;
    double time_spent;
    clock_t start, end;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory Allocation Error \n");
        exit(1);
    }

    for (i = 0; i < n; ++i) {
        printf("Enter the elements: \n");
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n");

    start = clock();
    selection_sort(arr, n);
    end = clock();

    printArray(arr, n);
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);

    return 0;
}