class Solution {
public:
    unordered_map<int,int> index;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i < inorder.size();i++){
            index[inorder[i]] = i;
        }
        
        return construct(postorder,0,postorder.size()-1,0, inorder.size());
    }
    
    TreeNode* construct(vector<int>& postorder,int postStart,int postEnd, int inStart, int inEnd)
    {
        if(postStart > postEnd || inStart > inEnd || inEnd < 0)
            return nullptr;
        
        int root = postorder[postEnd];
        
        TreeNode* curr = new TreeNode(root);
        
        int mid = index[root];
        
        curr ->left = construct(postorder,postStart,postStart + (mid - inStart)-1,inStart,mid-1);
        curr ->right = construct(postorder,postStart + (mid - inStart),postEnd-1, mid+1, inEnd);
        
        return curr;
    }
};

// Dry run to understand if you forget
