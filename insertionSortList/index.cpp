ListNode* insertionSortList(ListNode* head) {
    auto* curr{ head };
    ListNode* sortedHead{ nullptr };
    
    while (curr) {
        auto* dummy { curr->next };
        
        if (!sortedHead || sortedHead->val >= curr->val) {
            curr->next = sortedHead;
            sortedHead = curr;
        } else {
            auto* p{ sortedHead };
            
            while (p->next && p->next->val < curr->val) {
                p = p->next;
            }
            
            curr->next = p->next;
            p->next = curr;
        }
        
        curr = dummy;
    }
    
    return sortedHead;
}