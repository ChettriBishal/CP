class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *nnext = head->next;
        head->next = swapPairs(nnext->next);
        nnext ->next = head;
        return nnext;
    }
};
