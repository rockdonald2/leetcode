from typing import List, Tuple

""" 
* Given a sorted array convert it into height balanced BST
* Height balanced BST is defined as a binary tree in which the depth of the two subtrees of every node
* never differ by more than 1.
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # * 1. step search for the median value in the given array
    # * Because we know the array is sorted, then we can conclude that the median value is the middle value,
    # * if the array length is odd, and the greater one of the two if the array length is even 
    def search_for_median(self, nums: List[int]) -> Tuple:
        """
        Returns the median value, and its index in a tuple.
        If the list length is even, returns the greater one.
        """
        
        return (len(nums) // 2, nums[len(nums) // 2])

    def array_bf(self, root: TreeNode) -> List[int]:
        traverse_array = [root]
        return_array = []

        while len(traverse_array):
            curr = traverse_array.pop(0)

            if curr.left:
                traverse_array.append(curr.left)
            
            if curr.right:
                traverse_array.append(curr.right)

            return_array.append(curr.val)

        return return_array

    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not len(nums):
            return None

        median = self.search_for_median(nums)
        node = TreeNode(median[1])
        node.left = self.sortedArrayToBST(nums[:median[0]])
        node.right = self.sortedArrayToBST(nums[median[0] + 1:])

        return node

        

sol = Solution()
""" sol.sortedArrayToBST([-10, -3, 0, 5, 9])
sol.sortedArrayToBST([2, 5, 7, 9, 11, 13])
sol.sortedArrayToBST([-1, 0, 1, 2, 3])
sol.sortedArrayToBST([-100, -50, 0, 50, 100])
sol.sortedArrayToBST([-2, 2, 5, 6, 7, 8, 9, 11, 12])
sol.sortedArrayToBST([1])
sol.sortedArrayToBST([])
sol.sortedArrayToBST([1, 2])
sol.sortedArrayToBST([1, 2, 3]) """
arr = sol.array_bf(sol.sortedArrayToBST([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
print(arr)