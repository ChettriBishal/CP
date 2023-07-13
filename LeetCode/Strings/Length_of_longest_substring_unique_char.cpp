class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> ok; // to store characters present in the window
        int l = 0, r=0;
        while(l <= r && r < s.size()){
            if(ok.find(s[r]) == ok.end()){
                ok.insert(s[r++]); 
                res = max(res,(int)ok.size()); 
            }
            else{
                while(ok.find(s[r]) != ok.end()){
                    ok.erase(s[l++]); 
                }
            }
        }
        return res;
    }
};
