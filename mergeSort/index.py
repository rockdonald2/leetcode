from typing import List
from random import randint

def merge(leftArr, rightArr):
    result = []

    while len(leftArr) and len(rightArr):
        result.append(leftArr.pop(0) if leftArr[0] < rightArr[0] else rightArr.pop(0))

    result.extend(leftArr)
    result.extend(rightArr)

    return result

def mergeSort(arr):
    if len(arr) == 1:
        return arr

    midPoint = len(arr) // 2
    leftArr = arr[:midPoint]
    rightArr = arr[midPoint:]

    return merge(mergeSort(leftArr), mergeSort(rightArr))


arr = [randint(0, 100) for _ in range(15)]
print(mergeSort(arr))