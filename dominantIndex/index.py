from typing import List

class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        maxValue = max(nums)

        for n in nums:
            if n != maxValue and maxValue < 2 * n:
                return -1

        return nums.index(maxValue)


sol = Solution()
arr = [9, 2, 3, 4]
print(sol.dominantIndex(arr))