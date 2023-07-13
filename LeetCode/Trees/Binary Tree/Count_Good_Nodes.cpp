class Solution {
public:
    int goodNodes(TreeNode* root,int check= INT_MIN) {
        if(root == NULL)
            return 0;
        int left = goodNodes(root->left, max(check, root->val));
        int right = goodNodes(root->right, max(check, root->val));
        return left + right + (root->val >= check);
        
    }
};
