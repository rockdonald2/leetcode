#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head;
	ListNode* tail;

	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	if (l1->val <= l2->val) {
		head = l1;
		l1 = l1->next;
	}
	else {
		head = l2;
		l2 = l2->next;
	}

	tail = head;

	while (l1 != NULL && l2 != NULL) {
		if (l1->val < l2->val) {
			tail->next = l1;
			tail = l1;
			l1 = l1->next;
		}
		else {
			tail->next = l2;
			tail = l2;
			l2 = l2->next;
		}
	}

	if (l1 != NULL) {
		tail->next = l1;
	}
	else if (l2 != NULL) {
		tail->next = l2;
	}

	return head;
}

int main() {
	ListNode f1(1); ListNode f2(2); ListNode f3(4);
	f1.next = &f2; f2.next = &f3;
	ListNode s1(1); ListNode s2(3); ListNode s3(4);
	s1.next = &s2; s2.next = &s3;

	ListNode* sol = mergeTwoLists(&f1, &s1);

	return 0;
}