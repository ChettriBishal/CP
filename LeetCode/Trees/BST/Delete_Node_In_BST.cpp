class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
   
        if(root == NULL)
            return NULL;
        
        else if(key < root->val) 
            root ->left = deleteNode(root->left, key);
        
        else if(key > root->val)
            root ->right = deleteNode(root->right, key);
        
        else{
            // means now we found the key
            // case 1: No child
            if(root->left == NULL && root->right == NULL){
                delete root;
                root = NULL;
            }
            
            // case 2: 1 child
            else if(root ->left == NULL){
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            
            else if(root ->right == NULL){
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            // case 3: 2 children
            else{
                TreeNode* temp = findmin(root->right); // minimum value from right subtree
                root->val = temp ->val; // copy the value in targeted node
                root->right = deleteNode(root->right, temp->val); // delete duplicate from right subtree 
            }
            
        }
        
        return root;   
    }
    
    TreeNode* findmin(TreeNode* root){
        if(root->left == NULL)
            return root;
        
        return findmin(root->left);     
    }
};
