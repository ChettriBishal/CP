class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head,*trav;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1 == NULL && l2 == NULL)
            return NULL;
        if(l1->val <= l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head= l2;
            l2 = l2->next;
        }
        trav = head;
        while(l1 && l2){
            if(l1->val < l2->val){
                trav ->next = l1;
                trav = l1;
                l1 = l1->next;
            }
            else{
                trav ->next = l2;
                trav = l2;
                l2 = l2 ->next;
            }
        }
        while(l1){
            trav ->next = l1;
            trav = l1;
            l1 = l1 ->next;
        }
        while(l2){
            trav ->next = l2;
            trav = l2;
            l2 = l2->next;
        }
        return head;
    }
};
