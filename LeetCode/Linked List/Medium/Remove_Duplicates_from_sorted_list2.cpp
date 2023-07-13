class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dum = new ListNode(0);
        dum ->next = head;
        ListNode* prev = dum;
        ListNode* trav = head;
        while(trav){
            ListNode* curr = trav->next;
            if(curr && curr->val == trav->val){ // if the value is duplicate 
                while(curr && curr->val == trav->val)
                    curr = curr->next;
                prev->next = curr;
                trav = curr;
            }
            else{
                prev = trav;
                trav = trav->next;
            }
        }
        return dum->next;
    }
};
