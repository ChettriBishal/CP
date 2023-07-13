class Solution {
public:
    unordered_map<int, int> dp;
    int catalan(int n){ // to find the nth catalan number
        if(n <= 1)
            return 1;
        
        if(dp.find(n) != dp.end())
            return dp[n];
        
        int res = 0;
        
        for(int i=0;i<n;i++){
            res += catalan(i) * catalan(n - i-1); // using recurrence relation
        }
        
        dp[n] = res;
        return dp[n];
    }
    
    int numTrees(int n) {
        return catalan(n);
    }
};
