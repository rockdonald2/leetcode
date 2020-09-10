"""
Write a program to find the node at which the intersection of two singly linked lists begins.
"""

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        firstPtr = headA
        secondPtr = headB
        st = set()

        while firstPtr or secondPtr:
            st.add(firstPtr)
            st.add(secondPtr)

            if firstPtr == secondPtr:
                return firstPtr
            elif firstPtr and firstPtr.next in st:
                return firstPtr.next
            elif secondPtr and secondPtr.next in st:
                return secondPtr.next

            if firstPtr:
                firstPtr = firstPtr.next
            if secondPtr:
                secondPtr = secondPtr.next

        return None


sol = Solution()

headA = ListNode(4)
headA.next = ListNode(1)

headB = ListNode(5)
headB.next = ListNode(6)
headB.next.next = ListNode(1)

intersectVal = ListNode(8)
intersectVal.next = ListNode(4)
intersectVal.next.next = ListNode(5)

headA.next.next = intersectVal
headB.next.next.next = intersectVal

print(sol.getIntersectionNode(headA, headB).val)