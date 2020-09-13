from s import *

class MyQueue:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._st = Stack()


    def __str__(self):
        return str(self._st)


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        temp = Stack()

        while not self._st.empty():
            temp.push(self._st.pop())

        temp.push(x)

        while not temp.empty():
            self._st.push(temp.pop())


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self._st.empty():
            return None

        return self._st.pop()


    def peek(self) -> int:
        """
        Get the front element.
        """
        if self._st.empty():
            return None

        return self._st.top()


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return self._st.empty()


q = MyQueue()
q.push(1)
q.push(2)
q.push(3)
q.push(4)
q.push(5)
print(q.peek())
q.pop()
q.pop()
print(q)
print(q.peek())
print(q.empty())
q.pop()
print(q.peek())
q.pop()
print(q.peek())
q.push(6)
q.pop()
q.push(7)
print(q)
print(q.peek())
q.pop()
print(q.empty())
print(q)