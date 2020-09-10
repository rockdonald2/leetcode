"""
Remove all elements from a linked list of integers that have value val.
"""

class ListNode:
    def __init__(self, val: int=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if not head:
            return None

        node = head

        while node and node.next:
            if node.next.val == val:
                node.next = node.next.next

            if node.next and node.next.val != val:
                node = node.next
                
        if head and head.val == val:
            head = head.next

        return head


sol = Solution()

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(2)

result = sol.removeElements(head, 2)
result