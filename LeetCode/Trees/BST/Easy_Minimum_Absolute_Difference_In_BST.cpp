class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
      
        int min_diff = INT_MAX, val = -1;
      
        inorder(root, min_diff, val);
      
        return min_diff;
    }
    void inorder(TreeNode* root, int & min_diff, int& val){
        if(root->left)
            inorder(root->left, min_diff, val);
        
        // value is changed after getting into recursive call on the left side
        if(val >= 0)
            min_diff = min(min_diff, root->val - val); // current value - value from left subtree 
        
        val = root->val; // value is set as current node value
        
        if(root->right)
            inorder(root->right, min_diff, val);

    }
};
