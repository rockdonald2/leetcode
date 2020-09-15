from typing import List

""" class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        returnArr = [None, None]

        for i, e in enumerate(nums):
            try:
                index = nums.index(target - e, i + 1)
                returnArr[0] = i
                returnArr[1] = index
                break
            except:
                continue


        return returnArr """


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        _st = {}

        for i, e in enumerate(nums):
            if (target - e) in _st:
                return [_st[target - e], i]

            _st[e] = i



sol = Solution()
print(sol.twoSum([2,7,11,15], 18))