class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
      
        TreeNode* trav = dummy;
      
        stack< TreeNode* > st;
      
        while(!st.empty() || root ){
            if(root){
                st.push(root);
                root = root->left;
            }
            else{
                TreeNode* curr = st.top(); st.pop();
                root = curr->right;
                curr ->left = NULL;
                trav ->right = curr;
                trav = trav->right;
            }
        }
      
        return dummy->right;
    }
};
