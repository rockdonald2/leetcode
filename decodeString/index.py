class StackIterator:
    def __init__(self, StackInstance):
        self._inst = StackInstance
        self._i = len(StackInstance._st) - 1
        self._n = None


    def __next__(self):
        if self._i >= 0:
            self._n = self._inst._st[self._i]
            self._i -= 1
            return self._n
        else:
            raise StopIteration


class Stack:
    def __init__(self):
        self._st = []


    def __str__(self):
        return str(self._st)


    def __iter__(self):
        return StackIterator(self)


    def push(self, val: int) -> None:
        self._st.append(val)


    def pop(self) -> int:
        if self.empty():
            return None

        return self._st.pop()


    def top(self) -> int:
        if self.empty():
            return None

        return self._st[len(self._st) - 1]


    def empty(self) -> bool:
        return len(self._st) == 0


class Solution:
    def decodeString(self, s: str) -> str:
        if not s:
            return ''

        s = list(s)

        st = Stack()

        for i, c in enumerate(s):
            if c == '[':
                st.push((i, c))

        for br in st:
            sequence = ''
            startIndex = br[0] - 1
            endIndex = -1
            multiplier = 0
            it = 0

            while s[startIndex]:
                try:
                    multiplier = 10 ** it * int(s[startIndex]) + multiplier
                    it += 1
                    startIndex -= 1
                except:
                    break

            startIndex += 1

            for i in range(br[0] + 1, len(s)):
                if s[i] == ']':
                    endIndex = i
                    break

                sequence += s[i]

            sequenceToBeInserted = multiplier * sequence
            s[startIndex:endIndex + 1] = sequenceToBeInserted

        return ''.join(s)


sol = Solution()

result = sol.decodeString('leetcode')
print(result)