"""
4. Write a program to perform bubble sort using dynamic memory allocation.
Show the running time complexity w.r.t different input cases. Finally, comment that whether it
is matching with the expected complexity of O(n^2) or not.
"""
from timeit import default_timer as timer


def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


n = int(input("Enter the number of elements in the list: "))
arr = []
print("Enter the elements in the array: ")
for i in range(n):
    element = int(input())
    arr.append(element)

start = timer()
bubble_sort(arr)
end = timer()
print(end - start)

for i in range(len(arr)):
    print("%d " %arr[i])
