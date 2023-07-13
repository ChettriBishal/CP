class Solution {
public:
    ListNode* ghead;
    void reverse(ListNode* temp){
        if(temp -> next == nullptr){
            ghead = temp;
            return;
        }
        reverse(temp->next);
        ListNode* front = temp ->next;
        front-> next = temp;
        temp -> next = NULL;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
       
        reverse(head);
        
        return ghead;
    }
};
