from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        temp = [0 for _ in range(len(nums))]

        for i in range(0, len(nums)):
            temp[(i + k) % len(nums)] = nums[i]

        for i in range(0, len(nums)):
            nums[i] = temp[i]

sol = Solution()
arr = [1, 2, 3, 4, 5, 6, 7]
sol.rotate(arr, 3)
print(arr)