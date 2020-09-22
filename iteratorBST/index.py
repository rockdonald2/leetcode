from typing import List

class TreeNode:
    def __init__(self, val: int=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BSTIterator:
    def __init__(self, root: TreeNode):
        self._st = []
        self._index = 0
        self._traverse(root)

    def _traverse(self, root: TreeNode):
        if not root:
            return

        self._traverse(root.left)
        self._st.append(root)
        self._traverse(root.right)

    def next(self) -> int:
        """
        @return the next smallest number
        """
        if self.hasNext():
            old = self._index
            self._index += 1
            return self._st[old]

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        if self._index < len(self._st):
            return True
        else:
            return False


root = TreeNode(5)
root.left = TreeNode(1)
root.right = TreeNode(7)
root.right.right = TreeNode(8)
root.right.left = TreeNode(6)
it = BSTIterator(root)