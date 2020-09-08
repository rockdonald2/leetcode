from typing import List

"""
Given an array arr of integers, 
check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
"""

# easy solution, bruteforce
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        st = {}

        for n in arr:
            if (n % 2 == 0 and n / 2 in st) or n * 2 in st:
                return True
            else:
                st[n] = 1

        return False


sol = Solution()
print(sol.checkIfExist([3,1,7,11]))