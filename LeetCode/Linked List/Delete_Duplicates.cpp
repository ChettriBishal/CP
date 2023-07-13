class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* root = head;
        while(head->next != NULL){
            if(head ->val == head->next->val){
                head->next = head->next->next; // here head is not incremented forward
            }
            else
                head = head ->next; // head is incremented to next
        }
        return root;
    }
};
