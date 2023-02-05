"""
3. Write a program to perform selection sort using dynamic memory allocation.
Show the running time complexity w.r.t different input cases. Finally comment that whether it
is matching with the expected complexity of O(n^2) or not.
"""
from timeit import default_timer as timer


def selection_sort(array, size):
    for step in range(size):
        min_idx = step

        for i in range(step + 1, size):
            if array[i] < array[min_idx]:
                min_idx = i

        (array[step], array[min_idx]) = (array[min_idx], array[step])


n = int(input("Enter the number of elements in the list: "))
arr = []
print("Enter the elements in the array: ")
for i in range(n):
    element = int(input())
    arr.append(element)

start = timer()
selection_sort(arr, n)
end = timer()
print(end - start)

for i in range(len(arr)):
    print("%d " %arr[i])
