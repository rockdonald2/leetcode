"""
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
"""

class Solution:
    def climbStairs(self, n: int) -> int:
        cache = {}
        return self.climb(0, n, cache)

    def climb(self, i: int, n: int, cache: dict) -> int:
        if i > n:
            return 0
        
        if i == n:
            return 1

        if i in cache:
            return cache[i]

        result = self.climb(i + 1, n, cache) + self.climb(i + 2, n, cache)
        cache[i] = result
        return result

sol = Solution()
print(sol.climbStairs(5))
print(sol.climbStairs(3))