class Solution {
public:
    
     int Depth(TreeNode* root){ // to calculate the depth of binary tree
        if(root == NULL)
            return 0;
        return max(Depth(root->left) , Depth(root->right)) + 1;
    }
    
    void levelorder(TreeNode* root, int level, vector<vector<int>> & result)
    {
        if(root == NULL)
            return;
        result[level].push_back(root->val);
        levelorder(root->left, level-1, result);
        levelorder(root->right,level-1, result);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        int level = Depth(root); // max length of the vector
        
        for(int i=0;i<level;i++){
            result.push_back(vector<int>());
        }
        
        levelorder(root,level-1,result);
        
        return result; 
    }

};
