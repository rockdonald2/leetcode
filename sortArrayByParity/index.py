from typing import List

"""
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
"""

# easy solution, using Python's list concatenation
# second solution using stable sort
class Solution:
    """ def sortArrayByParity(self, A: List[int]) -> List[int]:
        return list(filter(lambda x: not (x % 2), A)) + list(filter(lambda x: x % 2, A)) """
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        A.sort(key=lambda x: x % 2)
        return A

sol = Solution()
print(sol.sortArrayByParity([3, 1, 2, 4]))