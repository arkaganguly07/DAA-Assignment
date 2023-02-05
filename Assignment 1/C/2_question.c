/*
2. Write a program to perform insertion sort using dynamic memory allocation.
   Show the running time complexity w.r.t different input cases. Finally comment
	that whether it is matching with the expected complexity of O(n^2) or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n) {
  int i, key, j;

  for (i = 0; i < n; ++i) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  int i;

  for (i = 0; i < n; ++i)
    printf("%d ", arr[i]);

  printf("\n");
}

int main() {
  int *arr, i, n;
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
  insertion_sort(arr, n);
  end = clock();

  printArray(arr, n);
  time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  printf("The elapsed time is %f seconds", time_spent);

  return 0;
}