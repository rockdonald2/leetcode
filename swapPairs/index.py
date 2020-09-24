class ListNode:
    def __init__(self, val: int=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head:
            return None

        if not head.next:
            return head

        if not head.next.next:
            newHead = head.next
            newHead.next = head
            head.next = None
            return newHead

        nextInRow = head.next.next
        newHead = head.next
        newHead.next = head
        head.next = self.swapPairs(nextInRow)
        return newHead


base = ListNode(1)
base.next = ListNode(2)
base.next.next = ListNode(3)
base.next.next.next = ListNode(4)

sol = Solution()
sol.swapPairs(base)