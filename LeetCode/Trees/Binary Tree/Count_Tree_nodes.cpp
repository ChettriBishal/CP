class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftsize = countNodes(root->left);
        int rightsize = countNodes(root->right);
        return leftsize + rightsize + 1;
    }
};
