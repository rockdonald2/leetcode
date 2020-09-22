class TreeNode:
    def __init__(self, val: int=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def validate(self, node: TreeNode, mi: int=None, ma: int=None) -> bool:
        if mi != None and mi >= node.val:
            return False

        if ma != None and ma <= node.val:
            return False

        if node.left and not self.validate(node.left, mi, node.val):
            return False

        if node.right and not self.validate(node.right, node.val, ma):
            return False

        return True

    def isValidBST(self, root: TreeNode) -> bool:
        if not root:
            return True

        return self.validate(root)


sol = Solution()
root = TreeNode(5)
root.left = TreeNode(1)
root.right = TreeNode(7)
root.right.right = TreeNode(8)
root.right.left = TreeNode(4)
print(sol.isValidBST(root))