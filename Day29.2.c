/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *first = NULL;   // head of result
    struct ListNode *ptr = NULL;     // tail pointer
    struct ListNode *new;            // new node
    
    int sum, carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        
        sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = sum % 10;
        new->next = NULL;

        if (first == NULL) {
            first = new;
            ptr = new;
        } else {
            ptr->next = new;
            ptr = new;
        }
    }

    return first;
}