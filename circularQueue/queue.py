# array solution
""" class Queue:
    def __init__(self):
        self._st = []

    def __str__(self):
        return str(self._st)

    def enqueue(self, val:int) -> None:
        self._st.append(val)

    def dequeue(self) -> int:
        try:
            return self._st.pop(0)
        except:
            return None """

# "pointer" solution
# we are not going to delete items from the storage, but increment the head index, which should be a "pointer"
class Queue:
    def __init__(self):
        self._st = []
        self.head = 0

    def __str__(self):
        return str(self._st[self.head:])

    def enqueue(self, val:int) -> None:
        self._st.append(val)

    def dequeue(self) -> int:
        self.head += 1
        return self._st[self.head - 1]


q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)

q.dequeue()
q.dequeue()
print(q)