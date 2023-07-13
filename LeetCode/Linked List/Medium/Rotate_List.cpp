class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp ->next;
            len++;
        }
        k %= len;
        
        temp = head;
        
        // traversing to the last node
        while(temp ->next) temp = temp ->next; 
        
        temp ->next = head; // pointing the last node to the first node
        
        ListNode* res;
        
        for(int i=0;i < len - k;i++)
            temp = temp ->next;
        
        res = temp ->next;
        
        temp ->next = NULL;
        
        return res;
    }
};
