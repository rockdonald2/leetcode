""" 
Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self):
        return f'Current Node\'s value = {self.val}, left child = {self.left.val}, right child = {self.right.val}'


class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root == None:
            return None

        # * If there're no children, and the Node's value isn't equal to the searched value, the searched value
        # * doesn't exist within the Tree
        if root.val != val and root.left == None and root.right == None:
            return None

        if root.val == val:
            return root
        elif root.val > val:
            return self.searchBST(root.left, val)
        elif root.val < val:
            return self.searchBST(root.right, val)


sol = Solution()

root = TreeNode(4, TreeNode(2), TreeNode(7))
root.left.left = TreeNode(1)
root.left.right = TreeNode(3)

result = sol.searchBST(root, 5) 
print(result)