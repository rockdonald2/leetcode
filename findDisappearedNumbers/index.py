from typing import List

""" 
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
"""

# easy solution, with dict
""" class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        if not nums:
            return []

        st = {}

        for n in nums:
            if n in st:
                st[n] += 1
            else:
                st[n] = 1
        
        m = 1
        return_arr = []
        for i in range(m, m + len(nums)):
            if i not in st:
                return_arr.append(i)

        return return_arr """

# complicated and more sophisticated solution
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # * The alternative solution uses the fact that the array elements are 1 <= arr[i] <= n
        # * that means, we can index the elements, and find the missing values
        # * we set each element negative, which appear
        # * the elements that do not appear, the array elem on that index remains positive

        for n in nums:
            index = abs(n) - 1
            nums[index] = -abs(nums[index])

        return [i + 1 for i, n in enumerate(nums) if n > 0]

sol = Solution()
print(sol.findDisappearedNumbers([1, 1]))