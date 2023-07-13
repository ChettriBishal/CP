class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        ListNode* even, *odd, *evenhead;
        odd = head;
        evenhead = head->next;
        even = evenhead;
        while(even && even ->next){
            odd ->next = odd->next ->next;
            even ->next = even ->next ->next;
            even = even ->next;
            odd = odd->next;
        }
        odd ->next = evenhead;
        return head;
    }
};
