from typing import List

"""
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.
"""

# easy solution
""" class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        return_arr = [x**2 for x in A]
        return_arr.sort()

        return return_arr """

# hard solution
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        left = 0 # points to the first element
        right = len(A) - 1 # points to the last element

        return_arr = []

        # * the main logic is that we use two pointers,
        # * because squared values are always positive,
        # * and the final array has to be sorted in a non-decreasing fashion
        # * we can always take the bigger value of the pointers,
        # * and append it to the start of the return array
        while left <= right:
            leftElem = abs(A[left])
            rightElem = abs(A[right])

            if leftElem > rightElem:
                return_arr = [leftElem ** 2] + return_arr
                left += 1
            else:
                return_arr = [rightElem ** 2] + return_arr
                right -= 1

        return return_arr

sol = Solution()
print(sol.sortedSquares([-7,-3,2,3,11]))