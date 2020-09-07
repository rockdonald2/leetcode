from typing import List

"""
Given an array nums and a value val, remove all instances of that value in-place and return the new length.
"""

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if not nums:
            return 0

        first = 0
        second = 1

        while second < len(nums):
            if nums[first] == val and nums[second] != val:
                temp = nums[first]
                nums[first] = nums[second]
                nums[second] = temp
                first += 1
                second += 1
            elif nums[first] == val:
                second += 1
            else:
                first += 1
                second += 1

        try:
            return nums.index(val)
        except:
            return len(nums)

sol = Solution()
""" arr = [0,1,2,2,3,0,4,2] """
arr = [3, 2, 2, 3]
sol.removeElement(arr, 3)
print(arr)