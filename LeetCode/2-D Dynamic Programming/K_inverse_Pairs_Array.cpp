class Solution {
    int MOD = 1e9 + 7;
public:
    int kInversePairs(int n, int k) {
        int dp[n+1][k+1];
        
        memset(dp,0,sizeof(dp));
        
        dp[0][0] = 1;
        
        for(int i=1;i <= n;i++){
            dp[i][0] = 1;
            for(int j=1;j <= k;j++){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
                if(j >= i)
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + MOD) % MOD;
            }
        }
        
        return dp[n][k];
    }
};


/*
dp[n][k] denotes the number of arrays that have k inverse pairs for array composed of 1 to n
we can establish the recursive relationship between dp[n][k] and dp[n-1][i]:

if we put n as the last number then all the k inverse pair should come from the first n-1 numbers
if we put n as the second last number then there's 1 inverse pair involves n so the rest k-1 comes from the first n-1 numbers
...
if we put n as the first number then there's n-1 inverse pairs involve n so the rest k-(n-1) comes from the first n-1 numbers

dp[n][k] = dp[n-1][k]+dp[n-1][k-1]+dp[n-1][k-2]+...+dp[n-1][k+1-n+1]+dp[n-1][k-n+1]


\/***********************************\/

Mathematical Proof:
dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + ......+dp[i-1][j-i+1] as per definition ---(1)

But dp[i][j-1] = dp[i-1][j-1] + dp[i-1][j-2] + ....+ dp[i-1][j-i] as per definition ---(2)

From (1) and (2)

dp[i][j] = dp[i-1][j] + (dp[i-1][j-1] + ......+dp[i-1][j-i+1]) + dp[i-1][j-i] - dp[i-1][j-i]
=>dp[i][j] = dp[i-1][j] + (dp[i-1][j-1] + ......+dp[i-1][j-i+1] + dp[i-1][j-i]) - dp[i-1][j-i]
=>dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-i]

*/
