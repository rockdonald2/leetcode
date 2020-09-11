"""
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
"""

class ListNode:
    def __init__(self, val: int, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        elif not l2:
            return l1

        firstPtr = l1
        secondPtr = l2

        newList = None

        if firstPtr.val <= secondPtr.val:
            newList = ListNode(firstPtr.val)
            firstPtr = firstPtr.next
        else:
            newList = ListNode(secondPtr.val)
            secondPtr = secondPtr.next

        node = newList

        while firstPtr and secondPtr:
            if firstPtr.val <= secondPtr.val:
                node.next = ListNode(firstPtr.val)
                node = node.next
                firstPtr = firstPtr.next
            else:
                node.next = ListNode(secondPtr.val)
                node = node.next
                secondPtr = secondPtr.next

        if firstPtr:
            node.next = firstPtr
        elif secondPtr:
            node.next = secondPtr

        return newList


sol = Solution()

l1 = ListNode(1)
l1.next = ListNode(2)
l1.next.next = ListNode(4)

l2 = ListNode(1)
l2.next = ListNode(3)
l2.next.next = ListNode(4)

mergedList = sol.mergeTwoLists(l1, l2)
pass