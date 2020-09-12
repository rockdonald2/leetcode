from typing import List

"""
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return [[]]

        traverseArr = [root, None]
        returnArr = [[]]

        while len(traverseArr) > 1:
            curr = traverseArr.pop(0)

            if curr == None:
                traverseArr.append(curr)
                returnArr.append([])
            else:
                returnArr[len(returnArr) - 1].append(curr.val)
                traverseArr.append(curr.left) if curr.left else ''
                traverseArr.append(curr.right) if curr.right else ''

        return returnArr