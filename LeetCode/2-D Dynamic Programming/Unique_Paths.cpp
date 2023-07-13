class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m +1][n +1];
        memset(dp,0,sizeof(dp));
        
        // only one unique path is possible for 1st row and 1st col
        
        for(int i= 1;i <= n;i++)
            dp[1][i] = 1;
        for(int j = 1;j <= m;j++)
            dp[j][1] = 1;
        
        for(int i=2;i<=m;i++){
            for(int j = 2;j <= n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m][n];
    }
};
