""" 
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
"""

class TreeNode:
    def __init__(self, val: int=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        if not root.left and not root.right:
            return 1

        if not root.left:
            return self.maxDepth(root.right) + 1

        if not root.right:
            return self.maxDepth(root.left) + 1

        l = self.maxDepth(root.left) + 1
        r = self.maxDepth(root.right) + 1

        return l if l > r else r