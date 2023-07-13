class Solution {
public:
    static const long inf = 3*1e9; // infinity
    bool isValidBST(TreeNode* root,long low = -inf, long high = inf) {
        if(root == NULL)
            return true;
        
        if(root ->val >= high || root->val <= low)
            return false;
        
        return isValidBST(root->left, low,root->val) &&
            isValidBST(root->right, root->val, high);
    }
};
