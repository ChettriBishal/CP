class Solution {
public:
    unordered_map<int,int> value_ind;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++) // storing the indices of values from inorder
            value_ind[inorder[i]] = i;
        
        return helper(0,0,inorder.size()-1,preorder);
    }
    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int> &preorder)
    {
        if(preStart > preorder.size() -1  || inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int rootIndex = value_ind[root->val]; // index of current root node in inorder array
        
        root ->left = helper(preStart + 1, inStart, rootIndex-1, preorder);
        root ->right = helper(preStart + (rootIndex - inStart) + 1, rootIndex + 1, inEnd, preorder);
        
        return root;
        
    }
};
/*
For index of right child
Our aim is to find out the index of right child for current node in the preorder array

* We know the index of current node in the preorder array - preStart (or whatever your call it), it's the root of a subtree

* Remember pre order traversal always visit all the node on left branch before going to the right ( root -> left -> ... -> right), therefore, we can get the immediate right child index by skipping all the node on the left branches/subtrees of current node


* The inorder array has this information exactly. Remember when we found the root in "inorder" array we immediately know how many nodes are on the left subtree and how many are on the right subtree


* Therefore the immediate right child index is preStart + numsOnLeft + 1 (remember in preorder traversal array root is always ahead of children nodes but you don't know which one is the left child which one is the right, and this is why we need inorder array)


* numsOnLeft = rootIndex - inStart.

*/
