/*


    ListNode* removeElements(ListNode* head, int val) {
        !Find new head first
        if (head == nullptr) 
            return head;
        ListNode dummy_node(-1, head);
        ListNode *prev = &dummy_node;
        while (head != nullptr) {
            if (head->val == val) {
                !Would need to delete here if the data had to be freed.
                prev->next = head->next;
            } else {
                prev = head;
            }
            head = head->next;
        }

        return dummy_node.next;
    
};







*/