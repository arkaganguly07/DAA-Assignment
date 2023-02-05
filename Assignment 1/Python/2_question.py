"""
2. Write a program to perform insertion sort using dynamic memory allocation.
Show the running time complexity w.r.t different input cases. Finally comment that whether it
is matching with the expected complexity of O(n^2) or not.
"""
from timeit import default_timer as timer


def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


n = int(input("Enter the number of elements in the list: "))
arr = []
print("Enter the elements in the array: ")
for i in range(n):
    element = int(input())
    arr.append(element)

start = timer()
insertionSort(arr)
end = timer()
print(end - start)

for i in range(len(arr)):
    print("%d " %arr[i])
