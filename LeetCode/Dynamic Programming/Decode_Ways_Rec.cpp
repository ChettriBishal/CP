class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        
        dp[n] = 1;
        
        return s.empty() ? 0: numDecodings(0,s,dp);
    }
    
    int numDecodings(int i, string& s, vector<int>&dp){
        
        int n = s.size();
        
        if(dp[i] != -1)
            return dp[i];
        
        if(s[i] == '0') // can't start with zero
            return dp[i] = 0;
        
        int num = numDecodings(i+1,s,dp); // one digit
        
        if(i + 1 < n){ // two digit
            string curr = string(1,s[i]) + s[i+1];
            if(stoi(curr) < 27){
                num += numDecodings(i+2,s,dp);
            }
        }
        
        return dp[i] = num;
    }
};
