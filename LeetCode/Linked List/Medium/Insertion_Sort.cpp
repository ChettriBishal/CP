class Solution {
public:
    ListNode* sorted; 
    ListNode* insertionSortList(ListNode* headref) {
        ListNode* curr = headref;
        sorted = NULL;
        while(curr){
            ListNode* nnext = curr->next;
            sortedInsert(curr);
            curr = nnext;
        }
        return sorted;
    }
    void sortedInsert(ListNode * node)
    {
        if(sorted == NULL || node->val <= sorted->val){
            node->next = sorted;
            sorted = node;
            return;
        }
        ListNode* curr = sorted;
        //Locate the node before the point of insertion
        while(curr->next && curr->next ->val < node->val)
            curr = curr->next;
        node->next = curr->next;
        curr->next = node;
    }
};
