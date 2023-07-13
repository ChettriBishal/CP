class Solution {
public:
    void pushLeft(TreeNode* root, stack<TreeNode* > & s){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode* > s1, s2;
        vector<int> result;
        
        pushLeft(root1, s1);
        pushLeft(root2, s2);
        
        while(!s1.empty() || !s2.empty()){
            stack<TreeNode*>& s = s2.empty() ? s1 : s1.empty() ? s2 :
                s1.top() ->val < s2.top() ->val ? s1: s2;
            
            TreeNode* curr = s.top(); s.pop();
            
            result.push_back(curr->val);
            
            pushLeft(curr->right, s);
        }
        return result;
    }
};

/*
Ternary operator 
            if(s1.empty())
                s = s2;
            else if(s2.empty())
                s = s1;
            else{
                if(s1.top() ->val < s2.top() ->val)
                    s = s1;
                else
                    s = s2;
            }
*/
