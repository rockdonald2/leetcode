from typing import List

"""
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
"""

# easy solution
""" class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        bottom = 0
        for top in range(0, m):
            if nums1[top] != 0 and nums1[top] <= nums2[bottom]:
                continue
            else:
                temp = nums1[top]
                nums1[top] = nums2[bottom]
                nums2[bottom] = temp
                nums2.sort()

                if nums2[bottom] == 0:
                    bottom += 1 """

# more sophisticated solution
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        # * we start two pointers, one for each array, pointing at the last non 0 element
        topEnd = (m - 1)
        bottomEnd = n - 1

        for i in range(m + n - 1, -1, -1):
            # * if there are no elements in the second array, the rest of it is sorted
            if bottomEnd < 0:
                break

            # * if there are no more elements in the first array, just place the second array in the right order
            # * at the start of the array
            if topEnd >= 0 and nums1[topEnd] > nums2[bottomEnd]:
                nums1[i] = nums1[topEnd]
                topEnd -= 1
            else:
                nums1[i] = nums2[bottomEnd]
                bottomEnd -= 1


sol = Solution()
arr1 = [1,2,3,0,0,0]
arr2 = [2,5,6]
sol.merge(arr1, len(arr1) - len(arr2), arr2, len(arr2))
print(arr1)