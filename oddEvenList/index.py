"""
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
"""

class ListNode:
    def __init__(self, val: int, next=None):
        self.val = val
        self.next = next


class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return

        odd = head
        even = head.next
        evenHead = even

        while even and even.next:
            odd.next = even.next
            odd = odd.next

            even.next = odd.next
            even = even.next

        odd.next = evenHead

        return head


sol = Solution()

arr = [1, 2, 3, 4, 5]

head = ListNode(arr[0])
node = head

for i in range(1, len(arr)):
    node.next = ListNode(arr[i])
    node = node.next

result = sol.oddEvenList(head)
pass