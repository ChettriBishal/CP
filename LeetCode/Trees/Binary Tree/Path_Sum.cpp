class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL) // leaf node
            return targetSum == root->val;
        bool fromleft = hasPathSum(root->left, targetSum- root->val);
        bool fromright = hasPathSum(root->right,targetSum - root->val);
        
        return fromleft || fromright;
    }
};
