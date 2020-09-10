from typing import Any

""" 
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
"""

class ListNode:
    def __init__(self, x: Any, next=None):
        self.val = x
        self.next = next

# easy solution
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head:
            return None

        slow = head
        fast = head
        st = []

        while fast and fast.next:
            st.append(slow)

            if fast.next in st:
                return fast.next
            elif fast.next.next in st:
                return fast.next.next

            slow = slow.next
            fast = fast.next.next

        return None


sol = Solution()
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = head
""" head.next.next.next.next.next = head.next.next """
print(sol.detectCycle(head).val)