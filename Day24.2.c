struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode temp;
    temp.next = head;
    
    struct ListNode *prev = &temp;
    struct ListNode *curr = head;
    
    while (curr != NULL) {
        
        if (curr->val == val) {
            prev->next = curr->next;   // remove node
        } else {
            prev = curr;               // move prev only if not deleted
        }
        
        curr = curr->next;             // move curr
    }
    
    return temp.next;   // new head
}