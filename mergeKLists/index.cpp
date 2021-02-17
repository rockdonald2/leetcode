#include <iostream>
#include "header.h"
#include <vector>

using namespace std;

ListNode* mergeKLists(vector<ListNode*>& lists);

int main() {
    vector<ListNode*> lists{};
    auto l1{LinkedList()};
    l1.insert(1); l1.insert(4); l1.insert(5);
    auto l2{LinkedList()};
    l2.insert(1); l2.insert(3); l2.insert(4);
    auto l3{LinkedList()};
    l3.insert(2); l3.insert(6);

    lists.push_back(l1.head); lists.push_back(l2.head); lists.push_back(l3.head);

    mergeKLists(lists);

    return 0;
}

void minHeap(vector<int> &arr, const int &i) {
    int l{2 * i + 1};
    int r{2 * i + 2};

    int min{};
    if (l < arr.size() && arr[l] < arr[i]) {
        min = l;
    } else {
        min = i;
    }

    if (r < arr.size() && arr[r] < arr[min]) {
        min = r;
    }

    if (min != i) {
        swap(arr[i], arr[min]);
        minHeap(arr, min);
    }
}

void buildMinHeap(vector<int> &arr) {
    for (int i{static_cast<int>(arr.size() / 2 - 1)}; i >= 0; --i) {
        minHeap(arr, i);
    }
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> heap{};

    for (const auto &l : lists) {
        auto *p{l};

        while (p) {
            heap.push_back(p->val);
            p = p->next;
        }
    }

    buildMinHeap(heap);

    ListNode *newHead{nullptr};
    ListNode *newBack{nullptr};
    while (!heap.empty()) {
        auto *p{new ListNode(heap.front())};

        if (!newHead) {
            newHead = p;
        } else {
            newBack->next = p;
        }

        newBack = p;
        if (heap.size() > 1) {
            heap[0] = heap[heap.size() - 1];
            minHeap(heap, 0);
        }
        heap.pop_back();
    }

    return newHead;
}