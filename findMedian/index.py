# easy, straight-forward solution
""" class MedianFinder:

    def __init__(self):
        self._st = []

    def __str__(self):
        return str(self._st)

    def addNum(self, num: int) -> None:
        self._st.append(num)

    def findMedian(self) -> float:
        self._st.sort()

        if not len(self._st) % 2:
            return (self._st[len(self._st) // 2 - 1] + self._st[len(self._st) // 2]) / 2
        else:
            return self._st[len(self._st) // 2] """

import bisect

class MedianFinder:
    def __init__(self):
        self._st = []

    def __str__(self):
        return str(self._st)

    def addNum(self, num: int) -> None:
        index = bisect.bisect_left(self._st, num)
        self._st.insert(index, num)

    def findMedian(self) -> float:
        if not len(self._st) % 2:
            return (self._st[len(self._st) // 2 - 1] + self._st[len(self._st) // 2]) / 2
        else:
            return self._st[len(self._st) // 2]


obj = MedianFinder()
obj.addNum(3)
obj.addNum(4)
obj.addNum(2)
print(obj)
print(obj.findMedian())