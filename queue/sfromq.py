from q import *

class MyStack:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._st = Queue()


    def __str__(self):
        return str(self._st)


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        temp = Queue()

        temp.push(x)

        while not self._st.empty():
            temp.push(self._st.pop())

        while not temp.empty():
            self._st.push(temp.pop())


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if self.empty():
            return None

        return self._st.pop()


    def top(self) -> int:
        """
        Get the top element.
        """
        if self.empty():
            return None

        return self._st.peek()


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self._st.empty()


s = MyStack()
s.push(1)
s.push(2)
s.push(3)
s.push(4)
s.push(5)
print(s)
print(s.top())
print(s.pop())
s.pop()
s.pop()
print(s)
print(s.top())