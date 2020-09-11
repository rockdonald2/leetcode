"""
Design your implementation of the linked list.
"""

class Node:
    def __init__(self, val: int, prev=None, next=None):
        self.val = val
        self.prev = prev
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

        node = self.head
        counter = 0

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
        newHead = Node(val, prev=None, next=self.head)
        if self.head:
            self.head.prev = newHead
        self.head = newHead


    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        if not self.head:
            return self.addAtHead(val)

        node = self.head

        while node.next:
            node = node.next

        newNode = Node(val, prev=node, next=None)
        node.next = newNode


    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if not self.head and index != 0:
            return

        if index == 0:
            return self.addAtHead(val)

        node = self.head
        counter = 0

        while node.next:
            if (counter + 1) == index:
                newNode = Node(val, prev=node, next=node.next)
                node.next = newNode
                node.next.prev = newNode
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

        node = self.head
        counter = 0

        while node.next:
            if (counter + 1) == index:
                if node.next.next:
                    node.next.next.prev = node
                node.next = node.next.next
                return

            node = node.next
            counter += 1


mylist = MyLinkedList()

mylist.addAtHead(1)
mylist.addAtTail(2)
mylist.addAtIndex(2, 3)
mylist.get(1)
mylist.deleteAtIndex(1)
mylist.get(1)
pass