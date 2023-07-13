class Solution {
public:
    // iterative implementation 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> s;
        while(root != NULL || s.empty() == false){
            while(root){ // firstly traverse to the left 
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};
