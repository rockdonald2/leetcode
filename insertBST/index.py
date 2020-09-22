class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def insert(self, node: TreeNode, val: int) -> None:
        if val < node.val:
            if node.left:
                self.insert(node.left, val)
            else:
                node.left = TreeNode(val)
        elif val > node.val:
            if node.right:
                self.insert(node.right, val)
            else:
                node.right = TreeNode(val)

    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            root = TreeNode(val)
        else:
            self.insert(root, val)

        return root


sol = Solution()
root = TreeNode(5)
root.left = TreeNode(1)
root.right = TreeNode(7)
root.right.right = TreeNode(8)
root.right.left = TreeNode(6)
sol.insertIntoBST(root, 0)