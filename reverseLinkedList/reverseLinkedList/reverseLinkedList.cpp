#include <iostream>

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
	ListNode* prev = NULL;
	ListNode* curr = head;
	ListNode* next = NULL;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

int main() {
	// 1->2->3->4->5
	ListNode first(1); ListNode second(2); ListNode third(3); ListNode fourth(4); ListNode fifth(5);
	first.next = &second; second.next = &third; third.next = &fourth; fourth.next = &fifth;

	reverseList(&first);

	return 0;
}