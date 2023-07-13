class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            bool x_exists = false;
            bool y_exists = false;
            
            for(int i=0;i < size;i++){ // all within the same level
                TreeNode* node = q.front(); q.pop();
                if(node->val == x) x_exists = true;
                if(node->val == y) y_exists = true;
                
                if(node->left && node->right){ // checking for same parents
                    if(node->left->val == x && node->right->val == y) 
                        return false;
                    if(node->left->val == y && node->right->val == x)
                        return false;
                }
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
            }
            if(x_exists && y_exists) return true; // if both exists in the same level but not as siblings
        }
        return false;
    }
};
