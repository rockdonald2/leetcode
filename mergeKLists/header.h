#include <iostream>

using namespace std;

struct ListNode {
    int val{};
    ListNode* next{nullptr};

    ListNode() = default;
    explicit ListNode(const int &v) : val(v) {}
};

struct LinkedList {
    ListNode *head{nullptr};
    ListNode *back{nullptr};

    LinkedList() = default;

    void insert(const int &val) {
        auto *p{new ListNode(val)};

        if (!this->head) {
            this->head = p;
        } else {
            this->back->next = p;
        }

        this->back = p;
    }

    friend ostream& operator<<(ostream &out, const LinkedList &l) {
        auto *p{l.head};

        while (p != l.back) {
            out << p->val << "->";
            p = p->next;
        }

        out << l.back->val << '\n';

        return out;
    }
};