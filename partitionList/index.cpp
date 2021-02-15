#include <iostream>
#include "header.h"

using namespace std;

ListNode* partition(ListNode*, int);

int main() {
    auto l{LinkedList()};

    l.insert(1);
    l.insert(4);
    l.insert(3);
    l.insert(2);
    l.insert(5);
    l.insert(2);

    l.head = partition(l.head, 3);

    cout << l;

    return 0;
}

ListNode* partition(ListNode* head, int x) {
    if (!head) return nullptr;

    ListNode *p{nullptr};
    ListNode *q{nullptr};
    ListNode *pHead{nullptr};
    ListNode *qHead{nullptr};

    auto *tmp{head};

    while (tmp) {
        if (tmp->val < x) {
            if (!p) {
                pHead = tmp;
            } else {
                p->next = tmp;
            }

            p = tmp;
        } else {
            if (!q) {
                qHead = tmp;
            } else {
                q->next = tmp;
            }

            q = tmp;
        }

        tmp = tmp->next;
    }

    if (!p) {
        pHead = qHead;
    } else {
        p->next = qHead;
    }

    if (q) {
        q->next = nullptr;
    }

    return pHead;
}