class Solution {
public:
    vector<vector<int>> paths;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        
        findpaths(root, path, targetSum);
        
        return paths;
    }
    void findpaths(TreeNode* root,vector<int>& path, int sum){
        if(root == NULL)
            return;
        
        path.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                paths.push_back(path);
                path.pop_back(); // backtracking
                return;
            } 
        }
        
        findpaths(root->left, path, sum- root ->val);
        findpaths(root->right, path, sum - root->val);
        
        path.pop_back(); // backtracking 
        
    }
};
