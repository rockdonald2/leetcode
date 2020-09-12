from typing import List

"""
Given a binary tree, return the preorder traversal of its nodes' values.
"""

class TreeNode:
    def __init__(self, val: int=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def insert(self, val:int=0):
        if self.val > val:
            if self.left:
                return self.left.insert(val)
            else:
                self.left = TreeNode(val)
                return
        elif self.val < val:
            if self.right:
                return self.right.insert(val)
            else:
                self.right = TreeNode(val)
                return


class Solution:
    def _preorder(self, root: TreeNode, arr: List[int]) -> None:
        arr.append(root.val)

        if root.left:
            self._preorder(root.left, arr)

        if root.right:
            self._preorder(root.right, arr)

    def preorderTraversal(self, root: TreeNode) -> List[int]:
        arr = []

        if not root:
            return arr

        self._preorder(root, arr)

        return arr


root = TreeNode(4)
root.insert(3)
root.insert(2)
root.insert(1)
root.insert(0)
root.insert(6)
root.insert(5)
root.insert(7)
root.insert(8)

sol = Solution()

sol.preorderTraversal(root)