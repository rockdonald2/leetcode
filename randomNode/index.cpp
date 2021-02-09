class Solution {
public:
    ListNode* h;
    int N = 0;
    
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        h = head;
    srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* curr = this->h;
        ListNode* result = curr;
        
        for (int i = 1; curr != nullptr; i++) {
            if (rand() % i == 0) {
                result = curr;
            }
            
            curr = curr->next;
        }
        
        return result->val;
    }
};