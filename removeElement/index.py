from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        firstPtr = 0
        secondPtr = 1

        while secondPtr < len(nums):
            if nums[firstPtr] == val and nums[secondPtr] != val:
                temp = nums[firstPtr]
                nums[firstPtr] = nums[secondPtr]
                nums[secondPtr] = temp
                firstPtr += 1
                secondPtr += 1
            elif nums[firstPtr] == val and nums[secondPtr] == val:
                secondPtr += 1
            else:
                firstPtr += 1
                secondPtr += 1

        return firstPtr if nums[firstPtr] == val else firstPtr + 1


sol = Solution()
arr = [0,1,2,2,3,0,4,2]
print(arr[:sol.removeElement(arr, 2)])