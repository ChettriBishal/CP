class Solution {
public:
    void flatten(TreeNode* root) {
        while(root){
            if(root->left && root->right){
                TreeNode* trav = root->left;
                while(trav->right)
                    trav = trav ->right;
                trav->right = root->right;
            }
            if(root -> left)
                root->right = root->left;
            root ->left = NULL;
            root = root ->right;
        }
    }
};
