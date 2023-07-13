class Solution {
public:
    int ans = 0;
    
    int sumNumbers(TreeNode* root) {
        SumUp(root,0);
        return ans;
    }
    void SumUp(TreeNode* root, int sum = 0)
    {
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL){
            ans += (sum* 10 + root->val);
        }
        
        SumUp(root->left, sum* 10 + root->val);
        SumUp(root->right,sum* 10 + root->val);
    }
};
