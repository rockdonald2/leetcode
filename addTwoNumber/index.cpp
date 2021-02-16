#include <iostream>
#include "header.h"

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main() {
    auto p{new LinkedList};
    auto q{new LinkedList};

    p->insert(9);
    p->insert(9);
    p->insert(9);

    q->insert(9);

    auto *r{addTwoNumbers(p->head, q->head)};

    while (r) {
        cout << r->val << ' ';
        r = r->next;
    }

    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto *p{l1};
    auto *q{l2};

    int pVal{};
    int qVal{};
    int carry{0};
    int sum{0};

    ListNode *newHead{};
    ListNode *newBack{};

    while (p || q) {
        if (p) {
            pVal = p->val;
        } else {
            pVal = 0;
        }

        if (q) {
            qVal = q->val;
        } else {
            qVal = 0;
        }

        sum = pVal + qVal;

        auto *t{new ListNode((sum + carry) % 10)};
        if (!newHead) {
            newHead = t;
            newBack = newHead;
        } else {
            newBack->next = t;
            newBack = newBack->next;
        }

        carry = (sum + carry) / 10;

        if (p) {
            p = p->next;
        }

        if (q) {
            q = q->next;
        }
    }

    if (carry) {
        newBack->next = new ListNode(1);
    }

    return newHead;
}