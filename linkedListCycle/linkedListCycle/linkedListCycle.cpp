#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
	if (head == NULL || head->next == NULL) return false;

	ListNode* slow = head;
	ListNode* fast = head;

	do {
		slow = slow->next;
		fast = fast->next->next;

		if (fast == NULL || fast->next == NULL) return false;
	} while (slow != fast);

	return true;
}

int main() {
	ListNode first(1);

	cout << hasCycle(nullptr) << endl;

	return 0;
}