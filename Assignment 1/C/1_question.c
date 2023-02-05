#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int linear_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

int binary_search(int arr[], int l ,int r, int x) {
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binary_search(arr, l, mid -1, x);

        return binary_search(arr, mid + 1, r, x);
    }

    return -1;
}

int main(void) {
    int *p, i, n, x;
    double time_linear = 0.0, time_binary = 0.0;

    printf("enter the total elements in the array \n");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    if (p == NULL)
    {
        printf("Memory Allocation Error\n");
        exit(1);
    }

    for (i = 0; i < n; ++i)
    {
        p[i] = i;
    }

    printf("\n");

    printf("Enter the value to be serached in the array: ");
    scanf("%d", &x);

    clock_t begin_1 = clock();
    int result_1 = linear_search(p, n, x);
    (result_1 == -1) ? printf("Absent \n", x) : printf("Element %d is present in the array \n", x);
    clock_t end_1 = clock();
    time_linear += (double)(end_1 - begin_1) / CLOCKS_PER_SEC;
    printf("The elapsed time in linear search is %f seconds \n", time_linear);

    clock_t begin_2 = clock();
    int result_2 = binary_search(p, 0, n - 1, x);
    (result_2 == -1) ? printf("Absent \n") : printf("Element %d is present in the array \n", x);
    clock_t end_2 = clock();
    time_binary += (double)(end_2 - begin_2) / CLOCKS_PER_SEC;
    printf("The elapsed time in binary search is %f seconds \n", time_binary);

    return 0;
}