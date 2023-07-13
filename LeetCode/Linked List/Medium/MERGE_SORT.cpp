class Solution {
public:
    ListNode* mergeList(ListNode* start, ListNode* end)
    {
        if(!start || !end)
            return !start ? end: start;
        ListNode* nHead= new ListNode(0);
        ListNode* temp = nHead;
        while(start && end){
            if(start ->val < end->val){
                temp->next= start;
                start = start->next;
            }
            else{
                temp ->next = end;
                end = end ->next;
            }
            temp = temp->next;
        }
        if(start){
            temp ->next = start;
        }
        else{
            temp ->next = end;
        }
        return nHead->next;
        
    }
    ListNode* Middle(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* slow, * fast;
        slow = fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // sorting via merge-sort
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL)
            return head;
        ListNode * head2, *mid;
        mid = Middle(head);
        head2 = mid->next; // head for the second half
        mid->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(head2);
        
        return mergeList(l1, l2);
        
    }
};
