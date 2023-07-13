class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        while(l1){
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2);
            l2 = l2->next;
        }
        ListNode* prev = NULL;
        int carry =0;
        while(!s1.empty() && !s2.empty()){
            int sum = (s1.top()) ->val + (s2.top())->val + carry;
            s1.pop();
            s2.pop();
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            temp ->next= prev;
            prev = temp;
        }
        while(!s1.empty()){
            int sum = (s1.top()->val) + carry;
            s1.pop();
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            temp ->next = prev;
            prev = temp;
        }
        while(!s2.empty()){
            int sum = (s2.top() ->val) + carry;
            s2.pop();
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            temp ->next = prev;
            prev = temp;
        }
        if(carry > 0){
            ListNode* temp = new ListNode(carry);
            temp ->next = prev;
            return temp;
        }
        return prev;
    }
};
