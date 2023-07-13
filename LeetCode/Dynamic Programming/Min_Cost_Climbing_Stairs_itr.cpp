class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            int a = dp[i-1] + cost[i-1];
            int b = 0;
            if(i > 1)
                b = dp[i-2] + cost[i-2];
            dp[i] = min(a,b);
        }
        return dp[n];
    }
};
