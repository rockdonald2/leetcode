"""
Design your implementation of the linked list.
"""

class Node:
    def __init__(self, val: int, next=None):
        self.val = val
        self.next = next

class MyLinkedList:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = None

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if not self.head:
            return -1

        counter = 0

        node = self.head

        while node:
            if counter == index:
                return node.val

            node = node.next
            counter += 1

        return -1

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        self.head = Node(val, self.head)

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        if not self.head:
            return self.addAtHead(val)

        node = self.head

        while node.next:
            node = node.next

        node.next = Node(val)

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if not self.head and index != 0:
            return

        counter = 0

        if index == counter:
            return self.addAtHead(val)

        node = self.head

        while node.next:
            if (counter + 1) == index:
                node.next = Node(val, node.next)
                return

            node = node.next
            counter += 1

        if (counter + 1) == index:
            return self.addAtTail(val)


    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if not self.head:
            return

        counter = 0

        if index == counter:
            self.head = self.head.next
            return

        node = self.head

        while node.next:
            if (counter + 1) == index:
                node.next = node.next.next
                return

            node = node.next
            counter += 1


# Your MyLinkedList object will be instantiated and called as such:
obj = MyLinkedList()
obj.addAtHead(7)
obj.addAtHead(2)
obj.addAtHead(1)
obj.addAtIndex(3, 0)
obj.deleteAtIndex(2)
obj.addAtHead(6)
obj.addAtTail(4)
obj.get(4)
obj.addAtHead(4)
obj.addAtIndex(5, 0)
obj.addAtHead(6)