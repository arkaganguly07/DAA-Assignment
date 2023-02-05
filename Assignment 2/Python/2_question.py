"""
2. Write a program to sort a list of element in an Array using Merge Sort. Show the
running time complexity w.r.t different input cases (best/average/worst).
"""

from timeit import default_timer as timer


def merge_sort(array):
    if len(array) > 1:
        r = len(array)//2
        L = array[:r]
        M = array[r:]
        merge_sort(L)
        merge_sort(M)
        i = j = k = 0
        while i < len(L) and j < len(M):
            if L[i] < M[j]:
                array[k] = L[i]
                i += 1
            else:
                array[k] = M[j]
                j += 1
            k += 1

        while i < len(L):
            array[k] = L[i]
            i += 1
            k += 1

        while j < len(M):
            array[k] = M[j]
            j += 1
            k += 1


def print_list(array):
    for i in range(len(array)):
        print(array[i], end=" ")
    print()



array = [6, 5, 12, 10, 9, 1]

start = timer()
merge_sort(array)
end = timer()

print("Sorted array is: ")
print_list(array)
print(end - start)
