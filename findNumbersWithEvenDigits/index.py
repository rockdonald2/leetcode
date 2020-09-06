from typing import List
from functools import reduce

"""
Given an array of integers, return how many of them contain an even number of digits.
"""

class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        evens = 0
        for n in nums:
            if not len(str(n)) % 2:
                evens += 1

        return evens

sol = Solution()
sol.findNumbers([12,345,2,6,7896])