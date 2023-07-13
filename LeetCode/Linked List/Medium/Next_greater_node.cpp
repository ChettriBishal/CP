class Solution {
public:
    stack<int> gon; // the elements encountered so far from back
    vector<int> res;
    void fromback(ListNode* node){
        if(node == NULL)
            return;
        fromback(node->next);
        while(!gon.empty() && gon.top() <= node->val)
            gon.pop();
        if(gon.empty())
            res.push_back(0);
        else
            res.push_back(gon.top());
        gon.push(node->val);
        
    }
    vector<int> nextLargerNodes(ListNode* head) {
        fromback(head);
        reverse(begin(res), end(res));
        return res;
    }
};
