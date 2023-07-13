class Solution {
public:
    vector<int> diStringMatch(string s) {
        unordered_set<int> ok;
        vector<int> res;
        int icnt = count(s.begin(),s.end(),'I');
        priority_queue<int,vector<int>,greater<int>> minh;
        priority_queue<int> maxh;
        for(int i=0;i<=icnt;i++)
            minh.push(i);
        for(int i=s.size();i>icnt;i--)
            maxh.push(i);
            
        for(int i=0;i<s.size();i++){
            if(s[i] == 'I'){
                res.push_back(minh.top());
                minh.pop();
            }
            else{
                res.push_back(maxh.top());
                maxh.pop();
            }
        }
        if(!maxh.empty()) res.push_back(maxh.top());
        if(!minh.empty()) res.push_back(minh.top());
        return res;
    }
};
