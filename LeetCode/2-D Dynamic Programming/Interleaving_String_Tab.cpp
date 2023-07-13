class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        
        if(n + m != s3.size())
            return false;
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
        
        dp[n][m] = true; //empty string
        
        for(int i = n;i >= 0;i--){
            for(int j= m;j >= 0;j--){
                if(i < n && s1[i] == s3[i+j] && dp[i+1][j])
                    dp[i][j] = true;
                if(j < m && s2[j] == s3[i+j] && dp[i][j+1])
                    dp[i][j] = true;
            }
        }
        
        return dp[0][0];
    }
};
