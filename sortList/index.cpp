#include <iostream>

using namespace std;

struct ListNode {
    int val{0};
    ListNode *next{nullptr};

    ListNode() = default;
    ListNode(const int &v) : val(v) {}
};

ListNode* sortList(ListNode *head);

int main() {
    auto *head{new ListNode(-1)};
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);

    auto *p{sortList(head)};
    while (p) {
        cout << p->val << ' ';
        p = p->next;
    }

    return 0;
}

ListNode* sortList(ListNode* head) {
    ListNode *newHead{nullptr};
    ListNode *newBack{nullptr};

    auto *p{head};
    while (p) {
        auto *next{p->next};

        if (!newHead) {
            newHead = p;
            newBack = p;
        } else if (p->val >= newBack->val) {
            auto *r{new ListNode(p->val)};

            newBack->next = r;
            newBack = r;
        } else {
            auto *q{newHead};
            bool found{false};

            while (q && !found) {
                if (q->val >= p->val) {
                    found = true;
                } else {
                    q = q->next;
                }
            }

            if (found) {
                auto *r{new ListNode};

                *r = *q;
                q->val = p->val;
                q->next = r;

                if (newBack == q) {
                    newBack = r;
                }
            } else {
                auto *r{new ListNode(p->val)};

                newBack->next = r;
                newBack = r;
            }
        }

        newBack->next = nullptr;

        p = next;
    }

    return newHead;
}
