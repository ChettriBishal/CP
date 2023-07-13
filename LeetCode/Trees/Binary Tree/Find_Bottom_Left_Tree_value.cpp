class Solution {
public:
    void find(TreeNode* root, int level, int & maxlevel, int & res)
    {
        if(root == NULL)
            return;
        find(root->left,++level,maxlevel, res);
        if(level > maxlevel){ // first checking for the left one 
            maxlevel = level;
            res = root->val;
        }
        find(root->right,level,maxlevel,res);
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxlevel = -1, res;
        find(root, 0, maxlevel,res);
        return res;
    }
};
