class Solution {
public:
    unordered_map<int,int> dp;
    int minCost(vector<int>& cost,int i){
        if(i<0) return 0;
        if(i == 0) return cost[0];
        if(i == 1) return cost[1];
        if(dp[i])
            return dp[i];
        int a = cost[i] + minCost(cost,i-1);
        int b= cost[i] + minCost(cost,i-2);
        return dp[i] = min(a,b);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
       return min(minCost(cost,n-1),minCost(cost,n-2));
    }
};
