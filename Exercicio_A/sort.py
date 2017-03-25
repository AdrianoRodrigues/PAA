
import sys
import random


def print_array(alist):
    """Print an array without brackets and commas."""
    print(*alist, sep=' ')


def insertionsort(alist):
    """Sorting an array using insertionsort algorithm."""
    for i in range(0, len(alist)):
        for j in range(i + 1, len(alist)):
            if alist[i] > alist[j]:
                alist[i], alist[j] = alist[j], alist[i]
    # return alist


def insertionsort_improved(alist):
    """Sorting an array using insertionsort algorithm with improvement."""
    for i in range(len(alist), 0, -1):
        changes = False
        for j in range(0, i-1):
            if alist[j] > alist[j + 1]:
                alist[j], alist[j + 1] = alist[j + 1], alist[j]
                changes = True

        if not changes:
            break
    # return alist


def merge_sorted_array(alist1, alist2):
    """Merge two ordered arrays."""
    i, j = 0, 0
    N = len(alist1) + len(alist2)
    merged_list = [None] * N
    for k in range(0, N):
        if j > (len(alist2) - 1):
            merged_list[k] = alist1[i]
            i += 1
        elif i > (len(alist1) - 1):
            merged_list[k] = alist2[j]
            j += 1
        elif alist1[i] <= alist2[j]:
            merged_list[k] = alist1[i]
            i += 1
        else:
            merged_list[k] = alist2[j]
            j += 1
    return merged_list


def mergesort(alist):
    """Sorting an array using mergesort algorithm."""
    if len(alist) > 1:
        middle = len(alist) // 2
        left = mergesort(alist[:middle])
        right = mergesort(alist[middle:])
        alist = merge_sorted_array(left, right)
    return alist


def heapify(alist, i, heap_size):
    if len(alist) > 1:
        left = (2 * i) + 1
        right = (2 * i) + 2
        largest = i
        if left < heap_size and alist[left] > alist[largest]:
            largest = left
        if right < heap_size and alist[right] > alist[largest]:
            largest = right
        if largest != i:
            alist[i], alist[largest] = alist[largest], alist[i]
            heapify(alist, largest, heap_size)


def build_heap(alist):
    """Build a heap from an array."""
    for i in range((len(alist) // 2), -1, -1):
        heapify(alist, i, len(alist))


def heapsort(alist):
    """Sorting an array using heapsort algorithm."""
    if len(alist) > 1:
        build_heap(alist)
        for i in range(len(alist)-1, 0, -1):
            if alist[0] > alist[i]:
                alist[0], alist[i] = alist[i], alist[0]
                heapify(alist, 0, i - 1)
    # return alist


def partition(alist, aleft, aright):
    pivot = alist[random.randint(aleft, aright)]    
    i = aleft - 1
    j = aright + 1
    while True:        
        while True:
            j -= 1
            if alist[j] <= pivot:
                break            
        while True:
            i += 1            
            if alist[i] >= pivot:
                break            
        if i < j:
            alist[i], alist[j] = alist[j], alist[i]
        else:
            return j


def quicksort(alist, aleft, aright):
    """Sorting an array using quicksort algorithm."""
    if aleft < aright:
        middle = partition(alist, aleft, aright)
        quicksort(alist, aleft, middle)
        quicksort(alist, middle + 1, aright)

while True:
    N = sys.stdin.readline()
    if N.strip() == '0':        
        break
    else:        
        V = [int(i) for i in sys.stdin.readline().split()]
        #insertionsort(V)
        #insertionsort_improved(V)
        #V = mergesort(V)
        #quicksort(V, 0, len(V) - 1)        
        heapsort(V)
        print_array(V)
