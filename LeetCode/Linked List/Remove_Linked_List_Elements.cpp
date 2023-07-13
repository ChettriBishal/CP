class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        ListNode* trav = head, *prev = NULL;
        while(trav ){
            if(trav == head && head ->val == val){ //  head = [7,7,7,7], val = 7
                ListNode* temp = head;
                head = head ->next;
                delete temp;
                trav = head;
                continue;
            }
            if(trav -> val == val){
                ListNode* front = trav ->next;
                if(prev)
                prev ->next = front;
                delete trav;
                trav = front;
            }
            else{
                prev = trav;
                trav = trav ->next;
            }
        }
        return head;
    }
};
