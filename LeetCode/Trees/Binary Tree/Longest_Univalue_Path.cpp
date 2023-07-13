class Solution {
public:
    int res = 0;
  
    int longestUnivaluePath(TreeNode* root) {
        GoBelow(root);
        return res;
    }
  
    int GoBelow(TreeNode* root)
    {
        if(root == NULL)
            return 0;
      
        int left = GoBelow(root->left); // below left child of root 
        int right = GoBelow(root->right); // below right child of root
        
        int checkLeft = 0, checkRight = 0; // including the current node 
        
        if(root->left && root->val == root->left->val)
            checkLeft += left + 1;
        if(root->right && root->val == root->right ->val)
            checkRight += right + 1;
        
        res = max(res, checkLeft + checkRight);
        
        return max(checkLeft, checkRight);
    }
};
