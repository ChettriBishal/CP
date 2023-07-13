class Solution {
public:
    // iterative
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];
        
        memset(dp,0,sizeof(dp));
        
        for(int i= n-1;i >=0;i--){ // <---
            dp[i][i] = 1;
            for(int j=i+1;j < n;j++){ // --->
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        
        return dp[0][n-1];
    }
};

/* Recursive */

class Solution {
public:
    // recursive + mem
    int dp[1001][1001];
    int longestPalindromeSubseq(string s) {
        
        memset(dp,-1,sizeof(dp));
        
        return helper(s,0, s.size()-1);
    }
    
    int helper(string&s,int i, int j){
        if(i == j)
            return 1;
        if(i > j) 
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == s[j]){ // if two ends of string are same
            return dp[i][j] = (2 + helper(s,i+1,j-1));
        }
        
        return dp[i][j] = max(helper(s,i+1,j), helper(s,i,j-1));
    }
};
