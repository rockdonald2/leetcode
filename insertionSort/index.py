from typing import List
from random import randint

def insertionSort(arr: List[int]) -> List[int]:
    for i in range(1, len(arr)):
        curr = arr[i]
        startIndex = i - 1

        while startIndex >= 0 and arr[startIndex] > curr:
            arr[startIndex + 1] = arr[startIndex]
            startIndex -= 1

        arr[startIndex + 1] = curr

    return arr


arr = [randint(0, 100) for _ in range(15)]
print(insertionSort(arr))