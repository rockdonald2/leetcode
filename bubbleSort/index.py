from typing import List
from random import randint

def selectionSort(arr: List[int]) -> List[int]:
    for i in range(len(arr)):
        swapped = False
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j + 1], arr[j] = arr[j], arr[j + 1]
                swapped = True

        if not swapped:
            break

    return arr


arr = [randint(0, 100) for _ in range(15)]
print(selectionSort(arr))