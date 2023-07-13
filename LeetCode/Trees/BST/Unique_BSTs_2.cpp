class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return genTrees(1,n);
    }
    
    vector<TreeNode*> genTrees(int start, int end){
        vector<TreeNode*> result;
        
        if(start > end)
            result.push_back(NULL);
        
        for(int idx = start; idx <= end; idx++){
            vector<TreeNode*> leftList = genTrees(start, idx -1);
            vector<TreeNode*> rightList = genTrees(idx+1, end);
            
            for(auto& left: leftList){
                for(auto& right: rightList){
                    TreeNode* root = new TreeNode(idx);
                    root->left = left;
                    root->right = right;
                    
                    result.push_back(root);
                }
            }
        }
        
        return result;  
    }
};
