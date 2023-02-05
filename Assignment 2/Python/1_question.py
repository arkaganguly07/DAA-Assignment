"""
1. Write a program to sort a list of element in an Array using Quick Sort. Show
the running time complexity w.r.t different input cases (best/average/worst).
"""

from timeit import default_timer as timer


def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1


def quick_sort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quick_sort(array, low, pi - 1)
        quick_sort(array, pi + 1, high)


data = [1, 7, 4, 1, 10, 9, -2]
print("Unsorted Array")
print(data)

size = len(data)

start = timer()
quick_sort(data, 0, size - 1)
end = timer()

print('Sorted Array in Ascending Order:')
print(data)
print(end - start)
