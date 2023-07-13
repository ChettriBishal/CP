class Solution {
public:
    // iterative implementation
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            result.push_back(curr->val);
            if(curr->right)
                s.push(curr->right);
            if(curr->left)
                s.push(curr->left);
        }
        return result;
    }
};
