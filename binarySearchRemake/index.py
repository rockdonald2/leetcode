from typing import List

def binarySearch(arr: List[int], val: int):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == val:
            return True
        elif val < arr[mid]:
            right = mid - 1
        elif val > arr[mid]:
            left = mid + 1

    return False

arr = [1, 2, 3, 4, 5]
result = binarySearch(arr, 4)
print(result)