class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL|| head->next == NULL)
            return head;
        
        ListNode* prev = NULL, *curr = head;
        
        while(left > 1){
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }
        
        ListNode* connection = prev;
        ListNode* tail  = curr;
        
        while(right > 0){
            ListNode* nnext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nnext;
            right--;
        }
        if(connection != NULL)
            connection->next = prev;
        else
            head = prev;
        
        tail->next = curr;
        
        return head;
    }
};
