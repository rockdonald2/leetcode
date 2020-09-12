from typing import List

"""
Given a binary tree, return the inorder traversal of its nodes' values.
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
    def _inorder(self, root: TreeNode, arr: List[int]) -> None:
        if root.left:
            self._inorder(root.left, arr)

        arr.append(root.val)

        if root.right:
            self._inorder(root.right, arr)

    def inorderTraversal(self, root: TreeNode) -> List[int]:
        arr = []

        if not root:
            return arr

        self._inorder(root, arr)

        return arr


root = TreeNode(1)
root.insert(2)
root.insert(3)

sol = Solution()

sol.inorderTraversal(root)