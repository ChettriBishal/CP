class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        if(root == p || root == q)
            return root;
        
        TreeNode* fromLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* fromRight = lowestCommonAncestor(root->right,p, q);
        
        if(fromLeft == NULL || fromRight == NULL)
            return fromLeft == NULL ? fromRight : fromLeft;
        
        return root;
        
    }
};
