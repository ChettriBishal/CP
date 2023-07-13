class Solution {
public:
    vector<int> vec;
    
    TreeNode* insert(TreeNode* root, int val){
        if(root == NULL){
            root = new TreeNode(val);
        }
        else if(root ->val < val){
            root->right = insert(root->right, val);
        }
        else{
            root ->left = insert(root->left, val);
        }
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        
        TreeNode* res = create(root,0, vec.size()-1);
        
        return res;
    }
    
    TreeNode* create(TreeNode* root, int l, int r){
        if(l > r)
            return NULL;
        
        int mid = (l + r)/2; // make the middle value as the root node 
        
        TreeNode* res = new TreeNode(vec[mid]);
        
        res ->left = create(res, l, mid-1); // recursively build the left subtree using first half values in vector
        res ->right = create(res, mid+1, r); // recursively build the right subtree using right half values in vector
        
        return res;
    }
    
    void inorder(TreeNode* root){
        
        if(root == NULL)
            return;
        
        inorder(root->left);
        
        vec.push_back(root->val);
        
        inorder(root->right);
    }
};
