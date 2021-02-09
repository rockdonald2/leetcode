#include <iostream>
#include <vector>

using namespace std;

int findKthElement(vector<int> &A, const int &l1, const int &r1, vector<int> &B, const int &l2, const int &r2, const int &k);

int main() {

	return 0;
}

int findKthElement(vector<int> &A, const int &l1, const int &r1, vector<int> &B, const int &l2, const int &r2, const int &k) {
	// if first array is empty
	if (l1 > r1) {
		return B[l2 + k - 1];
	} 

	// if second array is empty
	if (l2 > r2) {
		return A[l1 + k - 1];
	}

	int m1 = l1 + (r1 - l1) / 2;
	int m2 = l2 + (r2 - l2) / 2;
	int kc = (m1 - l1 + 1) + (m2 - l2 + 1);

	if (kc <= k) {
		// increase kc

		if (A[m1] < B[m2]) {
			// discard A[l1:m1 + 1]
			return findKthElement(A, m1 + 1, r1, B, l2, r2, k - (m1 - l1 + 1));
		} else {
			// discard B[l2:m2 + 1]
			return findKthElement(A, l1, r1, B, m2 + 1, r2, k - (m2 - l2 + 1));
		}
	} else {
		// decrease kc

		if (A[m1] < B[m2]) {
			return findKthElement(A, l1, r1, B, l2, m2 - 1, k);
		} else {
			return findKthElement(A, l1, m1 - 1, B, l2, r2, k);
		}
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if ((nums1.size() + nums2.size()) % 2) {
        return findKthElement(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, (nums1.size() + nums2.size()) / 2 + 1);
    } else {
        return (findKthElement(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, (nums1.size() + nums2.size()) / 2 + 1) + findKthElement(nums1, 0, nums1.size()- 1, nums2, 0, nums2.size() - 1, (nums1.size() + nums2.size()) / 2)) * 1.0 / 2;
    }
}