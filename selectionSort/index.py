from typing import List
from random import randint

def selectionSort(arr: List[int]) -> List[int]:
    for i in range(len(arr)):
        minElement = i

        for j in range(i + 1, len(arr)):
            if arr[j] < arr[minElement]:
                minElement = j

        if minElement != i:
            temp = arr[i]
            arr[i] = arr[minElement]
            arr[minElement] = temp

    return arr


arr = [randint(0, 1000000) for _ in range(1000)]
print(selectionSort(arr))