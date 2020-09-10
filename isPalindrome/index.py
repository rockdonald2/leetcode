"""
Given a singly linked list, determine if it is a palindrome.
"""

class ListNode:
    def __init__(self, val: int=0, next=None):
        self.val = val
        self.next = next

""" class Solution:
    def makeACopy(self, head: ListNode) -> ListNode:
        copyHead = ListNode(head.val)

        node = head.next
        copyNode = copyHead

        while node:
            copyNode.next = ListNode(node.val)
            node = node.next
            copyNode = copyNode.next

        return copyHead


    def reverse(self, head: ListNode) -> ListNode:
        if not head:
            return None

        node = head

        while node.next:
            upcoming = node.next
            oldHead = head

            node.next = upcoming.next
            head = upcoming
            head.next = oldHead

        return head

    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True

        reversedHead = self.reverse(self.makeACopy(head))

        firstPointer = head
        secondPointer = reversedHead

        while firstPointer and secondPointer:
            if firstPointer.val != secondPointer.val:
                return False

            firstPointer = firstPointer.next
            secondPointer = secondPointer.next

        return True """


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True

        st = []

        node = head

        while node:
            st.append(node.val)
            node = node.next

        node = head

        while node:
            if node.val != st.pop():
                return False

            node = node.next

        return True


sol = Solution()

arr = [1, 2]

head = ListNode(arr[0])
node = head

for i in range(1, len(arr)):
    node.next = ListNode(arr[i])
    node = node.next

result = sol.isPalindrome(head)
pass