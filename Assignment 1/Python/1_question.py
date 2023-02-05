"""
1. Write a program to search an element in an Array using dynamic memory
allocation. Apply different algorithm separately. Show the running time complexity
w.r.t different input cases (best/average/worst). Finally comment that which one is
better and why.
"""

from timeit import default_timer as timer


def binary_search(array, l, r, x):
    if r >= l:
        mid = l + (r - 1) // 2
        if array[mid] == x:
            return mid
        elif array[mid] > x:
            return binary_search(array, l, mid - 1, x)
        else:
            return binary_search(array, mid + 1, r, x)
    else:
        return -1


def linear_search(array, n, x):
    for j in range(0, n):
        if array[j] == x:
            return j
    return -1


n = int(input("Enter the number of elements in the list: "))
array = []
for i in range(n):
    element = i
    array.append(element)

x = int(input("enter the element to be searched: "))

start = timer()
result = binary_search(array, 0, len(array) - 1, x)
end = timer()

if result == -1:
    print("Absent")
else:
    print("Element %d is present in the array" % x)

print(end - start)

start_1 = timer()
result_1 = linear_search(array, n, x)
end_1 = timer()

if result_1 == -1:
    print("Absent")
else:
    print("Element %d is present in the array" % x)

print(end_1 - start_1)
