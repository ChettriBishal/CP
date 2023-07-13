vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> result;
    if(root == NULL)
        return result;
  
    while(root != NULL){
        if(root->left == NULL){
            result.push_back(root->val);
            root = root->right;
        }
        else{
            TreeNode* predecessor = root->left;
            while(predecessor -> right != NULL && predecessor ->right != root){
                predecessor = predecessor-> right;
            }
            if(predecessor ->right == NULL){
                predecessor ->right = root;
                root = root->left;
            }
            else{
                predecessor -> right = NULL;
                result.push_back(root->val);
                root = root->right;
            }
        }

    }
  
    return result;

}
