class Solution {
public:
    unordered_map<int,vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n == 0){
            return {};
        }
        
        if(n == 1){
            return {new TreeNode()};
        }
        
        if(dp[n].size() != 0){ // if already calculated 
            return dp[n];
        }
        
        vector<TreeNode*> res;
        
        for(int i=1;i < n;i += 2){ // full binary trees have to be odd
            int l = i, r = n - i-1; // -1 for root node 
            
            for(TreeNode* t1: allPossibleFBT(l)){
                for(TreeNode* t2: allPossibleFBT(r)){
                    TreeNode* root = new TreeNode();
                    root->left = t1;
                    root->right = t2;
                    res.push_back(root);
                }
            }
        }
        
        dp[n] = res;
        
        return res;
    }
};
/*
        root
        /   \
       /     \
       t1    t2
     
     
     
*/
