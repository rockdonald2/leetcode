#include <iostream>

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* currentNode(head->next);
	ListNode* currentHead(head);
	
	int i = 1, j = 1, k = 0;
	while (currentNode != NULL) {
		currentNode = currentNode->next;
		++j;
	}

	k = j - n;
	currentNode = head;

	if (k == 0) {
		return currentHead->next;
	}
	else if (k > 0) {
		currentHead = currentNode;

		while (i < k) {
			currentNode = currentNode->next;
			++i;
		}

		currentNode->next = currentNode->next->next;
	}

	return currentHead;
}

int main() {
	// 1->2->3->4->5
	ListNode first(1); ListNode second(2); ListNode third(3); ListNode fourth(4); ListNode fifth(5);
	first.next = &second; second.next = &third; third.next = &fourth; fourth.next = &fifth;

	removeNthFromEnd(&first, 1);

	return 0;
}