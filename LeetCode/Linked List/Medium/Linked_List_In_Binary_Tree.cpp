class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root);
    }
    
    bool dfs(ListNode* head, TreeNode* root)
    {
        if(root == NULL)
            return false;
        if(match(head,root))
            return true;
        return dfs(head, root->left) || dfs(head, root->right);
    }
    
    bool match(ListNode* head, TreeNode* root)
    {
        if(head == NULL) //means we compared all the nodes for linked list
            return true; 
        if(root == NULL || head->val != root->val)
            return false;
        return match(head->next, root->left) || match(head->next, root->right);
    }
    
    
};
