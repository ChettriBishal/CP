class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail = NULL) {
        if(head == tail)
            return NULL;
        ListNode* slow , *fast;
        slow = fast = head;
        while(fast != tail && fast ->next != tail){ // slow will point to the middle value in range [head, tail]
            slow = slow ->next;
            fast = fast ->next ->next;
        }
        // head ----->slow--------> tail
        TreeNode* root = new TreeNode(slow->val);
      
        root->left = sortedListToBST(head, slow);
        root->right = sortedListToBST(slow->next,tail);
        
        return root;
        
    }
};
