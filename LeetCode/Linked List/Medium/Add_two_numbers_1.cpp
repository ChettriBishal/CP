class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ok = new ListNode();
        ListNode* head = NULL;
        int carry = 0;
        while(l1 && l2){
            if(head == NULL){
                head = ok;
                int sum = l1 ->val + l2 ->val + carry;
                ok ->val = sum % 10;
                carry = sum / 10;
                
            }
            else{
                int sum = l1 ->val + l2->val + carry;
                ok->next = new ListNode(sum % 10);
                carry = sum / 10;
                ok = ok->next;
            }
            l1 = l1 ->next;
            l2 = l2 ->next;
        }
        while(l1){
            int sum = l1->val + carry;
            ok->next = new ListNode(sum % 10);
            ok = ok ->next;
            carry = sum / 10;
            l1 = l1 ->next;
        }
        while(l2){
            int sum = l2->val + carry;
            ok ->next = new ListNode(sum % 10);
            ok = ok ->next;
            carry = sum / 10;
            l2 = l2 ->next;
        }
        if(carry > 0)
            ok->next = new ListNode(carry);
        return head;
    }
};
