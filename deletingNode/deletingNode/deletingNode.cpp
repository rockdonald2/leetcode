#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    if (node->next != NULL) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
    else {
        return;
    }
}

int main() {
    // 1->2->3->4->5
    ListNode first(1); ListNode second(2); ListNode third(3); ListNode fourth(4); ListNode fifth(5);
    first.next = &second; second.next = &third; third.next = &fourth; fourth.next = &fifth;

    deleteNode(&second);

    return 0;
}