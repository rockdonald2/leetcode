ListNode* deleteDuplicates(ListNode* head) {
    if (!head) {
        return nullptr;
    } else if (!head->next) {
        return head;
    }
        
    auto *p{head};
        
    while (p->next) {
        if (p->val == p->next->val) {
            auto *q{ p->next };
            *p = *q;
            delete q;
        } else {
            p = p->next;
        }
    }
        
    return head;
}