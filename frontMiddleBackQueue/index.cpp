#include <iostream>

using namespace std;

class Queue {
private:
    struct ListNode {
        int val{};
        ListNode *next{nullptr};

        ListNode() = default;

        explicit ListNode(const int &v) : val(v) {}
    };

    ListNode *pivot{new ListNode};
    ListNode *head{pivot};
    int length{0};

public:
    Queue() = default;

    ~Queue() {
        ListNode *p{nullptr};

        while (this->head != this->pivot) {
            p = this->head;
            this->head = this->head->next;
            delete p;
        }
    }

    bool isEmpty() const {
        return this->head == this->pivot && this->length == 0;
    }

    int getLength() const {
        return this->length;
    }

    void insertFront(const int &v) {
        auto *q{new ListNode};

        *q = *(this->head);
        this->head->val = v;
        this->head->next = q;

        if (this->head == this->pivot) {
            this->pivot = q;
        }

        ++this->length;
    }

    void insertBack(const int &v) {
        auto *p{new ListNode};

        this->pivot->val = v;
        this->pivot->next = p;

        this->pivot = p;

        ++this->length;
    }

    int removeFront() {
        if (!this->isEmpty()) {
            auto *q{this->head};
            auto elem{q->val};
            this->head = this->head->next;
            delete q;
            --this->length;
            return elem;
        } else {
            return -1;
        }
    }

    int removeBack() {
        if (!this->isEmpty()) {
            auto *q{this->head};

            while (q->next != this->pivot) {
                q = q->next;
            }

            auto *r{this->pivot};
            auto elem{q->val};
            *q = *(this->pivot);
            this->pivot = q;
            delete r;
            --this->length;
            return elem;
        } else {
            return -1;
        }
    }

    friend ostream &operator<<(ostream &out, const Queue &q) {
        auto *p{q.head};

        while (p != q.pivot) {
            out << p->val << ' ';
            p = p->next;
        }

        return out;
    }
};

class FrontMiddleBackQueue {
private:
    Queue lowerHalf{};
    Queue upperHalf{};
    int length{0};

public:
    FrontMiddleBackQueue() = default;

    bool isEmpty() const {
        return lowerHalf.isEmpty() && upperHalf.isEmpty();
    }

    void pushFront(const int &v) {
        lowerHalf.insertFront(v);

        if (lowerHalf.getLength() > upperHalf.getLength()) {
            upperHalf.insertFront(lowerHalf.removeBack());
        }

        ++this->length;
    }

    void pushMiddle(const int &v) {
        if (lowerHalf.getLength() == upperHalf.getLength()) {
            upperHalf.insertFront(v);
        } else {
            lowerHalf.insertBack(v);
        }

        ++this->length;
    }

    void pushBack(const int &v) {
        upperHalf.insertBack(v);

        if (upperHalf.getLength() > (lowerHalf.getLength() + 1)) {
            lowerHalf.insertBack(upperHalf.removeFront());
        }

        ++this->length;
    }

    int popFront() {
        if (!this->isEmpty()) {
            --this->length;

            int r{};
            if (lowerHalf.isEmpty()) {
                r = upperHalf.removeFront();
            } else {
                r = lowerHalf.removeFront();
            }

            if (upperHalf.getLength() > (lowerHalf.getLength() + 1)) {
                lowerHalf.insertBack(upperHalf.removeFront());
            }

            return r;
        } else {
            return -1;
        }
    }

    int popMiddle() {
        if (!this->isEmpty()) {
            --this->length;

            int r{};
            if (lowerHalf.getLength() == upperHalf.getLength()) {
                r = lowerHalf.removeBack();
            } else {
                r = upperHalf.removeFront();
            }

            return r;
        } else {
            return -1;
        }
    }

    int popBack() {
        if (!this->isEmpty()) {
            --this->length;

            auto r{upperHalf.removeBack()};

            if (lowerHalf.getLength() > upperHalf.getLength()) {
                upperHalf.insertFront(lowerHalf.removeBack());
            }

            return r;
        } else {
            return -1;
        }
    }

    friend ostream &operator<<(ostream &out, const FrontMiddleBackQueue &q) {
        out << q.lowerHalf << q.upperHalf << ' ';
        return out;
    }
};

int main() {
    auto *q{new FrontMiddleBackQueue};

    q->pushFront(1);
    q->pushBack(2);
    q->pushMiddle(3);
    q->pushMiddle(4);

    q->popFront();
    q->popMiddle();
    q->popMiddle();
    q->popBack();

    return 0;
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */