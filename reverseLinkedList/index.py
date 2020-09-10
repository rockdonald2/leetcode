"""
Reverse a singly linked list.
"""

class ListNode:
    def __init__(self, val: int=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return 

        node = head

        while node.next:
            upcoming = node.next
            oldHead = head

            node.next = upcoming.next
            head = upcoming
            head.next = oldHead

        return head


sol = Solution()

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)

result = sol.reverseList(head)
result