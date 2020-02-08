#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> intersection{};

	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	/*
	
	Alapvetően ez az algoritmus úgy működik, hogy mindkét vektort rendezzük növekvő sorrendben, majd végiglépdelünk a vektorokon
		a következő folyamat szerint:
			- ha az első vektor értéke a kisebb, akkor az első vektor mutatóját növelem
			- ha a második vektor értéke a kisebb, akkor a második vektor mutatóját növelem
			- ha a kettő egyenlő, akkor közbevág a két vektor, és kiírjuk az elemet, mindkét mutatót növelve.
	
	*/

	int i = 0, j = 0;

	while (i < nums1.size() && j < nums2.size()) {
		if (nums1[i] < nums2[j]) {
			++i;
		}
		else if (nums1[i] > nums2[j]) {
			++j;
		}
		else {
			intersection.push_back(nums1[i]);
			++i;
			++j;
		}
	}

	return intersection;
}

int main() {
	vector<int> nums1{ 4, 9, 5 };
	vector<int> nums2{ 9, 4, 9, 8, 4 };

	vector<int> sol = intersect(nums1, nums2);

	for (vector<int>::const_iterator it = sol.begin(); it != sol.end(); ++it) {
		cout << *it << " ";
	}

	return 0;
}