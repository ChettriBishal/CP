class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
       int prev = -10001;
        vector<int> res(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i] == c) prev = i;
            res[i] = i - prev;
        }
        for(int i=s.size()-1;i>-1;i--){
            if(s[i] == c) prev = i;
            res[i] = min(res[i],abs(prev-i));
        }
       
        return res;
    }
};
