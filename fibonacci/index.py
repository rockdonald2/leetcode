"""
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.
"""

class Solution:
    cache = {}

    def fib(self, N: int) -> int:
        if N in self.cache:
            return self.cache[N]
        else:
            if N >= 2:
                result = self.fib(N - 1) + self.fib(N - 2)
            else:
                result = N

            self.cache[N] = result
            return result


sol = Solution()
print(sol.fib(3))