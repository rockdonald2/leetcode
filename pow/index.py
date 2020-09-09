"""
Implement pow(x, n), which calculates x raised to the power n (i.e. xn).
"""

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0

        if n == 0:
            return 1
        
        if n < 0:
            return 1 / x * self.myPow(x, n + 1)
        elif n > 0:
            return x * self.myPow(x, n - 1)


sol = Solution()
result = sol.myPow(0.00001, 2147483647)
print(result)