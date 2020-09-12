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
    def _postorder(self, root: TreeNode, arr: List[int]) -> None:
        if root.left:
            self._postorder(root.left, arr)

        if root.right:
            self._postorder(root.right, arr)

        arr.append(root.val)

    def postorderTraversal(self, root: TreeNode) -> List[int]:
        arr = []

        if not root:
            return arr

        self._postorder(root, arr)

        return arr