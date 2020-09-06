from typing import List

""" 
Given a binary array, find the maximum number of consecutive 1s in the array
"""

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        # * first step, to find the starting point, which is the first 1
        # * if there are no 1s in the array, return 0
        try:
            startingPoint = nums.index(1)
        except:
            return 0
        
        # * we iterate through the array, starting from the first 1
        windowStart = -1
        windowEnd = -1
        largestWindow = 0
        # * three variables which memorizes the windows

        i = startingPoint
        while i < len(nums):
            if nums[i] == 1:
                windowStart = i
                windowEnd = windowStart

                for j in range(i + 1, len(nums)):
                    if nums[j] != 1:
                        break

                    windowEnd += 1

                currGap = windowEnd - windowStart + 1
                if currGap > largestWindow:
                    largestWindow = currGap

                i = windowEnd + 1
            else:
                i += 1

        return largestWindow

sol = Solution()

sol.findMaxConsecutiveOnes([0, 1, 1, 1])