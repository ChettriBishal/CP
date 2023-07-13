class Solution {
public:
    // two pointer approach
    int lo, lps;
    string longestPalindrome(string s) {
        lo = 0;
        lps = 1;
        
        for(int i=0;i < s.size()-1;i++){
            helper(s,i,i); // odd length
            helper(s,i,i+1); // even length
        }
        
        return s.substr(lo,lps);
    }
    void helper(string &s, int i, int j){ // extends palindrome on both sides till it's feasible
        
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            if(lps < j - i + 1){
                lps = j - i + 1;
                lo = i;
            }
            i--, j++;
        }
        
    }
};
