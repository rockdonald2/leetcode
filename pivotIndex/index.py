from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if sum(nums[:i]) == sum(nums[i + 1:]):
                return i

        return -1

sol = Solution()
nums = [10, 0, 5, 5]
print(sol.pivotIndex(nums))