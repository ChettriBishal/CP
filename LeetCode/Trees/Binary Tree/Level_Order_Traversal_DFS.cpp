class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        DFS(root, 0);
        return res;
    }
    
    void DFS(TreeNode* root,int level)
    {
        if(root == NULL)
            return;
        if(level == res.size()){
            res.push_back(vector<int>());
        }
        res[level].push_back(root->val);
        
        DFS(root->left, level + 1);
        DFS(root->right, level + 1);
    }
};
