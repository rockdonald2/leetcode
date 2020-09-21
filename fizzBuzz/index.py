from typing import List

class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        rArr = []

        for i in range(1, n + 1):
            r = ''

            if not i % 3:
                r += 'Fizz'
            if not i % 5:
                r += 'Buzz'

            if not r:
                r = str(i)

            rArr.append(r)

        return rArr


sol = Solution()
print(sol.fizzBuzz(15))