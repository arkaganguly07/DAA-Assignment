"""
3. Write a program to sort a list of element in an Array using Heap Sort. Show the
running time complexity w.r.t different input cases (best/average/worst).
"""

from timeit import default_timer as timer


def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heap_sort(arr):
    n = len(arr)

    for i in range(n // 2, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)


def print_list(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()



arr = [1, 12, 9, 5, 6, 10]

start = timer()
heap_sort(arr)
end = timer()

print("Sorted array is")
print_list(arr)

print(end - start)
