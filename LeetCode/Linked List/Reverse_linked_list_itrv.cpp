class Solution {
public:  // iterative implementation 
    ListNode* reverseList(ListNode* head) {
        ListNode* curr, *prev, *nnext; 
        curr = head;
        prev = NULL;
        while(curr != NULL){
            nnext = curr -> next;
            curr ->next = prev;
            prev = curr;
            curr = nnext;
        }
        return prev; // the head finally 
    }
};
