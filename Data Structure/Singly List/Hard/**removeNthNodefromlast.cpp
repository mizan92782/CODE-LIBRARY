/*

*
 ListNode* removeNthFromEnd(ListNode* head, int n) {

       https://chat.openai.com/share/cf945fe6-fb7e-4fc6-bd87-3f8aced20c54

        !initally set fast and slow as head node
        ListNode *fast = head, *slow = head;

        !forward fast node n time
        for (int i = 0; i < n; i++) fast = fast->next;



        !if fast==NULL ,that means n==length of list,that means from last n will be first node
        ! so delete first node
        if (!fast) return head->next;



        ! ok,now fast forwad n time than slow in first,when fist readch
        ! to end slow reach just previous node of deleted node

        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }


*/