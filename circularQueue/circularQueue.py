"""
Design your implementation of the circular queue.
"""

class MyCircularQueue:
    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self._st = []
        self.size = k


    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self.isFull():
            return False

        self._st.append(value)
        return True


    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False

        self._st.pop(0)
        return True


    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        return self._st[0]


    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        return self._st[len(self._st) - 1]


    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        if not self._st:
            return True
        else:
            return False


    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        if len(self._st) == self.size:
            return True
        else:
            return False
