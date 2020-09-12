"""
Design your implementation of the circular queue.
"""

class MyCircularQueue:
    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self.size = k
        self._st = [None for _ in range(0, k)]
        self.head = -1
        self.tail = -1


    def __str__(self):
        return 'Queue: {}, head: {}, tail:{}'.format(str(self._st), self.head, self.tail)


    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self.isFull():
            return False

        self.tail = (self.tail + 1) % self.size
        self._st[self.tail] = value

        if self.head == -1:
            self.head = self.tail

        return True


    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False

        self._st[self.head] = None
        self.head = (self.head + 1) % self.size

        if self._st[self.tail] == None:
            self.head = -1
            self.tail = -1

        return True


    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        if self.isEmpty():
            return -1

        return self._st[self.head]


    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        if self.isEmpty():
            return -1

        return self._st[self.tail]


    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        if self.head == -1 and self.tail == -1:
            return True
        else:
            return False


    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        if self.tail >= self.head:
            return (self.tail - self.head) == (self.size - 1)
        elif self.tail < self.head:
            return (self.size - (self.head - self.tail)) == (self.size - 1)

        return False


q = MyCircularQueue(4)
q.enQueue(3)
q.enQueue(7)
q.enQueue(2)
q.enQueue(5)
print(q)
q.deQueue()
print(q)
q.enQueue(4)
q.enQueue(2)
print(q)