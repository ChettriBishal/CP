class Solution {
public:
    string s1, s2, s3;
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        vector<vector<int>> dp(s1.size() +1,vector<int>(s2.size()+1,-1));
        
        int ok = dfs(0,0,dp);
        
        return ok ? true: false;
    }
    
    int dfs(int i, int j, vector<vector<int>>& dp){
        if(i == s1.size() && j == s2.size())
            return true;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i < s1.size() && s1[i] == s3[i+j] && dfs(i+1,j,dp))
            return dp[i][j] = 1;
        
        if(j < s2.size() && s2[j] == s3[i+j] && dfs(i,j+1,dp))
            return dp[i][j] = 1;
        
        dp[i][j] = 0;
        
        return 0;
    }
};
