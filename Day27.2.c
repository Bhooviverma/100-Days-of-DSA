//Function to remove a loop in the linked list.
void removeLoop(struct Node* head)
{
    if (head == NULL || head->next == NULL)
        return;

    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // If loop does not exist
    if (slow != fast)
        return;

    // Move slow to head
    slow = head;

    // If loop starts at head
    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    }
    else {
        // Move both pointers to find start of loop
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Remove loop
    fast->next = NULL;
}