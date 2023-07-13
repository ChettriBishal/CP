class Solution {
public:
    TreeNode* deepestNode(TreeNode* root){
        if(root == NULL)
            return NULL;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp->right)  // see that we first push right child if it exists 
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }
        return temp;
    }
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* res = deepestNode(root);
        return res->val;
    }
};
