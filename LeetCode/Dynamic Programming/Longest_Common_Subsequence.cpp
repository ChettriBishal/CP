class Solution {
public:
    int lcs(string& s1,string& s2, int i, int j, vector<vector<int>> & dp)
    {
        if(i == s1.length() || j == s2.length())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + lcs(s1, s2, i+1, j+1, dp);
        
        int opt1 = lcs(s1,s2, i+1, j, dp); // moving pointer only for the first one
        int opt2 = lcs(s1,s2, i, j+1, dp); // moving pointer only for the second one
        
        return dp[i][j] = max(opt1, opt2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return lcs(text1,text2,0,0,dp);
    }
};
