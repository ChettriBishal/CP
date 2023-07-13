class Solution {
public:
    // iterative implementation
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)
            return {};
        
        stack<TreeNode*> a,b;
        a.push(root);
        
        while(!a.empty()){
            TreeNode* curr = a.top();
            a.pop();
            if(curr->left)
                a.push(curr->left);
            if(curr->right)
                a.push(curr->right);
            b.push(curr);
        }
        
        vector<int> res;
        
        while(!b.empty()){
            TreeNode* curr = b.top();
            b.pop();
            res.push_back(curr->val);
        }
        
        return res;
    }
};
