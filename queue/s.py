class Stack:
    def __init__(self):
        self._st = []


    def __str__(self):
        return str(self._st)


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