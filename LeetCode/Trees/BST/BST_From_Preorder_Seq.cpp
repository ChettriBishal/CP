class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return construct(preorder,0,preorder.size());
    }
    
    TreeNode* construct(vector<int>& vec, int l, int r)
    {
        if(l == r)
            return NULL;
        
        TreeNode* root = new TreeNode(vec[l]);
        int next_max; // index of next greater value than vec[l] 
        
        for(next_max = l;next_max < r ;next_max++){
            if(vec[next_max] > vec[l])
                break;
        }
        
        root->left = construct(vec,l+1,next_max);
        root->right = construct(vec,next_max,r);        
        return root;
    }

};
