struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *first = head;
    struct ListNode *ptr;
    int count = 0;

    // Step 1: Count nodes
    for(ptr = first; ptr != NULL; ptr = ptr->next)
        count++;

    // Step 2: Move to middle (count/2)
    ptr = first;
    for(int i = 0; i < count/2; i++)
        ptr = ptr->next;

    return ptr;
}